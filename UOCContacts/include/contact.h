#ifndef __CONTACT_H__
#define __CONTACT_H__
#include "csv.h"
#include "date.h"

// Maximum length of an identity document
#define MAX_PERSON_DOCUMENT_LEN 15
#define MAX_PERSON 100
#define MAX_STRING_LEN 100

// Ex 1: Define data types here...

typedef struct tCoordinate {
    float latitude;
    float longitude;
}tCoordinate;

typedef struct tTimePosition {
    tCoordinate coordinates;
    char* id;
    tDateTime datetime;
}tTimePosition;

typedef struct tGeolocationData {
    tTimePosition* location;
    int count;
}tGeolocationData;


// Ex 2: Define your methods here ....
void geoData_init(tGeolocationData *geoData);
void contact_parse(tTimePosition *timePos, tCSVEntry csvEntry);
void geoData_add(tGeolocationData *geoData, tTimePosition timePos);
void geoData_del(tGeolocationData *geoData, char *id, tDateTime dateTime);
void geoData_print(tGeolocationData geoData);
int geoData_find(tGeolocationData geoData, char *id, tDateTime dateTime);
void location_free(tTimePosition* locationData);
void geoData_free(tGeolocationData *geoData);
#endif
