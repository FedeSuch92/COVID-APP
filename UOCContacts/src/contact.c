#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "contact.h"

// Parse a tDateTime from string information
void dateTime_parse(tDateTime* dateTime, const char* date, const char* time) {
    // Check output data
    assert(dateTime != NULL);

    // Check input date
    assert(date != NULL);
    assert(strlen(date) == 10);

    // Check input time
    assert(time != NULL);
    assert(strlen(time) == 5);

    // Parse the input date
    sscanf(date, "%d/%d/%d", &(dateTime->date.day), &(dateTime->date.month), &(dateTime->date.year));

    // Parse the input time
    sscanf(time, "%d:%d", &(dateTime->time.hour), &(dateTime->time.minutes));
}

// Compare two tDateTime structures and return true if they contain the same value or false otherwise.
bool dateTime_cmp(tDateTime dateTime1, tDateTime dateTime2) {
    if (dateTime1.date.day != dateTime2.date.day || dateTime1.date.month != dateTime2.date.month || dateTime1.date.year != dateTime2.date.year) {
        return false;
    }

    return dateTime1.time.hour == dateTime2.time.hour && dateTime1.time.minutes == dateTime2.time.minutes;
}

// EX2: Implement your methods here....
void geoData_init(tGeolocationData *geoData){

    assert(geoData != NULL);
    geoData->location = NULL;
    geoData->count = 0;
}

void contact_parse(tTimePosition *timePos, tCSVEntry csvEntry){

    // Check input data
    assert(timePos != NULL);
    
    // Check entry fields
    assert(csv_numFields(csvEntry) == 5);
    
    // Copy identity document data
    timePos->id = (char*) malloc((strlen(csvEntry.fields[0]) + 1) * sizeof(char));
    assert(timePos->id != NULL);
    memset(timePos->id, 0, (strlen(csvEntry.fields[0]) + 1) * sizeof(char));
    csv_getAsString(csvEntry, 0, timePos->id, strlen(csvEntry.fields[0]) + 1);
    
    // Check date lenght
    assert(strlen(csvEntry.fields[1]) == 10);
    // Copy date
    sscanf(csvEntry.fields[1], "%d/%d/%d", &(timePos->datetime.date.day),
           &(timePos->datetime.date.month), &(timePos->datetime.date.year));
           
    // Check time lenght
    assert(strlen(csvEntry.fields[2]) == 5);
    // Copy time
    sscanf(csvEntry.fields[2], "%d:%d", &(timePos->datetime.time.hour),
           &(timePos->datetime.time.minutes));
           
    // Copy latitute
    timePos->coordinates.latitude = csv_getAsReal(csvEntry, 3);
    
    // Copy longitude
    timePos->coordinates.longitude = csv_getAsReal(csvEntry, 4);
}

void geoData_add(tGeolocationData *geoData, tTimePosition timePos){

    int pos;

    // Check input geoData
    assert(geoData != NULL);

    pos = geoData_find(*geoData, timePos.id, timePos.datetime);

    if (pos == -1) {

        if (geoData->count == 0) {
            geoData->location = (tTimePosition*) malloc(sizeof(tTimePosition));
        } else {
            geoData->location = (tTimePosition*) realloc(geoData->location, (geoData->count + 1) * sizeof(tTimePosition));
        }
        
        assert(geoData->location != NULL);
        
        // Copy the id data
        geoData->location[geoData->count].id = (char*) malloc((strlen(timePos.id) + 1) * sizeof(char));
        assert(geoData->location[geoData->count].id != NULL);
        strcpy(geoData->location[geoData->count].id, timePos.id);
        // Copy the datetime
        geoData->location[geoData->count].datetime = timePos.datetime;
        // Copy the coordinates
        geoData->location[geoData->count].coordinates.latitude = timePos.coordinates.latitude;
        geoData->location[geoData->count].coordinates.longitude = timePos.coordinates.longitude;
        // Increase the number of elements by 1
        geoData->count++;
    }
}

// Remove the geolocation data of the person with the id provided
void geoData_del(tGeolocationData *geoData, char *id, tDateTime dateTime){

    int k, pos;

    // Check input geoData
    assert(geoData != NULL);

    pos = geoData_find(*geoData, id, dateTime);

    if(pos > 0){
        // Remove current position memory
        location_free(&(geoData->location[pos]));
        // Shift elements in geoData
        for(k = pos ; k < geoData->count - 1; k++) {
            // Copy address of element on position k+1 to position k
            geoData->location[k] = geoData->location[k + 1];
        }
        // Update the number of elements
        geoData->count--;
        // Resize the userd memory
        if (geoData->count == 0) {
            // No element remaining
            free(geoData->location);
            geoData->location = NULL;
        } else {
            // Still some elements are remaining
            geoData->location = (tTimePosition*) realloc(geoData->location, geoData->count * sizeof(tTimePosition));
        }
    }
}

// Print the geolocation data
void geoData_print(tGeolocationData geoData){
    int i;

    for(i = 0; i < geoData.count; i++){
        // Print position and document
        printf("%d:%s;", i, geoData.location[i].id);
        // Print date
        printf("%02d/%02d/%04d;", geoData.location[i].datetime.date.day,
            geoData.location[i].datetime.date.month,
            geoData.location[i].datetime.date.year);
        // Print time
        printf("%d:%d;",geoData.location[i].datetime.time.hour,
            geoData.location[i].datetime.time.minutes);
        // Print coordinates
        printf("%.4f;%.4f\n",geoData.location[i].coordinates.latitude,
            geoData.location[i].coordinates.longitude);
    }
}

// Return the position of the timeposition for the person with the id provided
int geoData_find(tGeolocationData geoData, char *id, tDateTime dateTime) {
    int i, pos;
    
    pos = -1;
    i = 0;
    while (i < geoData.count && pos == -1){

        if (!strcmp(geoData.location[i].id, id) && dateTime_cmp(geoData.location[i].datetime, dateTime)) {
            pos = i; 
        }
        i++;
    }
    return pos;
}

// Remove the locationData from a tTimePosition
void location_free(tTimePosition* locationData) {
    // Check input data
    assert(locationData != NULL);
    
    // Release id data
    if (locationData->id != NULL) free(locationData->id);
    locationData->id = NULL;
}

void geoData_free(tGeolocationData *geoData) {
    
    int i;
    
    assert(geoData != NULL);

    // Remove contents
    for(i = 0; i < geoData->count; i++){
        location_free(&(geoData->location[i]));
    }
    
    // Release memory
    if (geoData->count > 0) {
        free(geoData->location);
        geoData_init(geoData);
    }
}
