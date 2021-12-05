#ifndef __UOCCONTACTS_API__H
#define __UOCCONTACTS_API__H
#include <stdbool.h>
#include "error.h"
#include "csv.h"
#include "contact.h"
#include "person.h"

// Type that stores all the application data
typedef struct _ApiData {
    //////////////////////////////////
    // Ex PR1 2: 
    tPopulation population;
    tGeolocationData geolocation;
    /////////////////////////////////
    
} tApiData;

// Get the API version information
const char* api_version();

// Load data from a CSV file. If reset is true, remove previous data
tApiError api_loadData(tApiData* data, const char* filename, bool reset);

// Add a new entry
tApiError api_addDataEntry(tApiData* data, tCSVEntry entry);

// Free all used memory
tApiError api_freeData(tApiData* data);

// Initialize the data structure
tApiError api_initData(tApiData* data);

// Get person data
tApiError api_findPerson(tApiData* data, const char* document, tCSVEntry* person);

// Get all geolocation data for a given person
tApiError api_getPersonGeolocation(tApiData* data, const char* document, tCSVData* geodata);

// Remove a person
tApiError api_removePerson(tApiData* data, const char* document);


#endif // __UOCCONTACTS_API__H