#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "date.h"

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
