#include <stdio.h>
#include <assert.h>
#include "csv.h"
#include "api.h"
#include <string.h>
#include <stdlib.h>

#define FILE_READ_BUFFER_SIZE 2048

// Get the API version information
const char* api_version() {
    return "UOC PP 20211";
}

// Load data from a CSV file. If reset is true, remove previous data
tApiError api_loadData(tApiData* data, const char* filename, bool reset) {
    tApiError error;
    FILE *fin;    
    char buffer[FILE_READ_BUFFER_SIZE];
    tCSVEntry entry;
    
    // Check input data
    assert( data != NULL );
    assert(filename != NULL);
    
    // Reset current data    
    if (reset) {
        // Remove previous information
        error = api_freeData(data);
        if (error != E_SUCCESS) {
            return error;
        }
        
        // Initialize the data
        error = api_initData(data);
        if (error != E_SUCCESS) {
            return error;
        }
    }

    // Open the input file
    fin = fopen(filename, "r");
    if (fin == NULL) {
        return E_FILE_NOT_FOUND;
    }
    
    // Read file line by line
    while (fgets(buffer, FILE_READ_BUFFER_SIZE, fin)) {
        // Remove new line character     
        buffer[strcspn(buffer, "\n\r")] = '\0';
        
        csv_initEntry(&entry);
        csv_parseEntry(&entry, buffer, NULL);
        // Add this new entry to the api Data
        error = api_addDataEntry(data, entry);
        if (error != E_SUCCESS) {
            return error;
        }
    }
    
    fclose(fin);
    
    return E_SUCCESS;
}

// Add a new entry
tApiError api_addDataEntry(tApiData* data, tCSVEntry entry) { 
    
    //////////////////////////////////
    // Ex PR1 2
    char *id;
    
    // Check input data
    assert(data != NULL);
    
    // Copy identity document data from entry
    id = (char*) malloc((strlen(entry.fields[0]) + 1) * sizeof(char));
    memset(id, 0, (strlen(entry.fields[0]) + 1) * sizeof(char));
    csv_getAsString(entry, 0, id, strlen(entry.fields[0]) + 1);
    
    // Check if the entry type is invalid
    if (strcmp(csv_getType(&entry), "PERSON") && strcmp(csv_getType(&entry), "GEOLOCATION")) {
        return E_INVALID_ENTRY_TYPE;
    }
    
    // Check if the entry format is invalid
    if ((!strcmp(csv_getType(&entry), "PERSON") && csv_numFields(entry) != 7) || (!strcmp(csv_getType(&entry), "GEOLOCATION") && csv_numFields(entry) != 5)) {
        return E_INVALID_ENTRY_FORMAT;
    }
    
    // Check if the entry is from a person already added
    if ((!strcmp(csv_getType(&entry), "PERSON") && population_find(data->population, id) != -1))  {
        // Return that the person was not found
        return E_DUPLICATED_ENTRY;
    }
    
    if (!strcmp(csv_getType(&entry), "PERSON")) {
        tPerson person;
        person_parse(&person, entry);
        population_add(&data->population, person);
    }
    
    if (!strcmp(csv_getType(&entry), "GEOLOCATION") && population_find(data->population, id) == -1) {
        // Return that the person was not found
        return E_PERSON_NOT_FOUND;
    }
    
    if (!strcmp(csv_getType(&entry), "GEOLOCATION")) {
        tTimePosition timePos;
        contact_parse(&timePos, entry);
        if (geoData_find(data->geolocation, id, timePos.datetime) != -1) {
            return E_DUPLICATED_ENTRY;
        }
        geoData_add(&data->geolocation, timePos);
    }

    return E_SUCCESS;
}


// Free all used memory
tApiError api_freeData(tApiData* data) {
    //////////////////////////////////
    // Ex PR1 2:
    // Release memory of geolocation data
    geoData_free(&data->geolocation);
    // Release memory of population data
    population_free(&data->population);
    // Init api_initData
    api_initData(data);
    /////////////////////////////////
    return E_SUCCESS;
}

// Initialize the data structure
tApiError api_initData(tApiData* data) {
        
    //////////////////////////////////
    // Ex PR1 2: 
    // Init geolocation data
    geoData_init(&data->geolocation);
    // Init population data
    population_init(&data->population);
    /////////////////////////////////
    return E_SUCCESS;
}

// Get person data
tApiError api_findPerson(tApiData* data, const char* document, tCSVEntry* person) {
    //////////////////////////////////
    // Ex PR1 3
    int i;
    char input[FILE_READ_BUFFER_SIZE];
    
    // Get position in population of person with the document provided
    i = population_find(data->population, document);
     
    if (i == -1) {
        // Return when the person was not found
        return E_PERSON_NOT_FOUND;
    }
     
     // Copy in input the data from population in pos
     sprintf(input, "%s;%s;%s;%s;%s;%s;%02d/%02d/%04d\n",
            data->population.elems[i].document, data->population.elems[i].name,
            data->population.elems[i].surname, data->population.elems[i].email,
            data->population.elems[i].address, data->population.elems[i].cp,
            data->population.elems[i].birthday.day, data->population.elems[i].birthday.month,
            data->population.elems[i].birthday.year);
    
    // Parte input into person
    csv_parseEntry(person, input, "PERSON");
    /////////////////////////////////
    return E_SUCCESS;
}

// Get all geolocation data for a given person
tApiError api_getPersonGeolocation(tApiData* data, const char* document, tCSVData* geodata) {
    //////////////////////////////////
    // Ex PR1 3
    int i, pos;
    char* buffer;
    
    // Look for the person and get the position
    pos = population_find(data->population, document);
    
    // The person does not exist
    if (pos == -1) {
        // Return that the person was not found
        return E_PERSON_NOT_FOUND;
    }
    
    //  Init geodata. Init tCSVData structure
    csv_init(geodata);
    
    // Request new memory space
    buffer = (char*) malloc(FILE_READ_BUFFER_SIZE);
    
    // Look for the each geolocation data with the document provided
    for (i = 0; i < data->geolocation.count; i++) {
        if (strcmp(data->geolocation.location[i].id, document) == 0) {
            // Copy the geolocation data in position i into buffer
            sprintf(buffer, "%s;%d/%d/%d;%d:%d;%.4f;%.4f\n", data->geolocation.location[i].id, 
                    data->geolocation.location[i].datetime.date.day,
                    data->geolocation.location[i].datetime.date.month,
                    data->geolocation.location[i].datetime.date.year,
                    data->geolocation.location[i].datetime.time.hour,
                    data->geolocation.location[i].datetime.time.minutes,
                    data->geolocation.location[i].coordinates.latitude,
                    data->geolocation.location[i].coordinates.longitude);
            
            //Add buffer to geoData
            csv_addStrEntry(geodata, buffer, "GEOLOCATION");
        }
    }        
    /////////////////////////////////
    return E_SUCCESS;
}

// Remove a person
tApiError api_removePerson(tApiData* data, const char* document) {
    //////////////////////////////////
    // Ex PR1 3
    int pos, i;
    tCSVData geodata;
    tCSVEntry* entry = NULL;
    tTimePosition timePos;
    
    // check input data
    assert(data != NULL);
    
    // Get the position of the person for the document
    pos = population_find(data->population, document);
    
    if (pos == -1) {
        // The person was not found
        return E_PERSON_NOT_FOUND;
    }
    
    // Remove the person with the document provided
    population_del(&data->population, document);
    
    // Init geodata
    csv_init(&geodata);
    
    //  Get all geolocations with document and save them into geodata
    api_getPersonGeolocation(data, document, &geodata);
    
    for (i = 0; i < csv_numEntries(geodata); i++) {
        // Get the entry from geodata in position i
        entry = csv_getEntry(geodata, i);
        //Parse the entry into timePos
        contact_parse(&timePos, *entry);
        // Delete geodata with the id and datetime given
        geoData_del(&data->geolocation, timePos.id, timePos.datetime);
    }   
    /////////////////////////////////     
    return E_SUCCESS;
}
