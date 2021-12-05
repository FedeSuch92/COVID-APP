#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "test_pr1.h"
#include "api.h"

// Run all tests for PR1
bool run_pr1(tTestSuite* test_suite, const char* input) {
    bool ok = true;
    tTestSection* section = NULL;

    assert(test_suite != NULL);

    testSuite_addSection(test_suite, "PR1", "Tests for PR1 exercices");

    section = testSuite_getSection(test_suite, "PR1");
    assert(section != NULL);

    ok = run_pr1_ex1(section, input);
    ok = run_pr1_ex2(section, input) && ok;
    ok = run_pr1_ex3(section, input) && ok;

    return ok;
}

// Run all tests for Exercice 1 of PR1
bool run_pr1_ex1(tTestSection* test_section, const char* input) {
    bool passed = true, failed = false;
    const char* version;
    
    /////////////////////////////
    /////  PR1 EX1 TEST 1  //////
    /////////////////////////////
    failed = false;
    start_test(test_section, "PR1_EX1_1", "Read version information.");
    // Get the version+
    version = api_version();
    if (strcmp(version, "UOC PP 20211") != 0) {
        failed = true;
        passed = false;
    }
    end_test(test_section, "PR1_EX1_1", !failed);
    
    return passed;
}

// Run all tests for Exercice 2 of PR1
bool run_pr1_ex2(tTestSection* test_section, const char* input) {
    tApiData data;
    tApiError error;
    tCSVEntry entry;
    tCSVEntry entry2;
    bool passed = true, failed = false;
    bool fail_all = false;
    
    /////////////////////////////
    /////  PR1 EX2 TEST 1  //////
    /////////////////////////////
    failed = false;
    start_test(test_section, "PR1_EX2_1", "Initialize the API data structure");
    // Initialize the data    
    error = api_initData(&data);
    if (error != E_SUCCESS) {
        failed = true;
        passed = false;
        fail_all = true;
    }
    end_test(test_section, "PR1_EX2_1", !failed);
    
    /////////////////////////////
    /////  PR1 EX2 TEST 2  //////
    /////////////////////////////
    failed = false;
    start_test(test_section, "PR1_EX2_2", "Load data from file");
    // Load basic data to the API
    if (fail_all) {
        failed = true;
    } else {
        error = api_loadData(&data, input, true);
        if (error != E_SUCCESS) {
            failed = true;
            passed = false;
        }
    }
    end_test(test_section, "PR1_EX2_2", !failed);

    /////////////////////////////
    /////  PR1 EX2 TEST 3  //////
    /////////////////////////////
    failed = false;
    start_test(test_section, "PR1_EX2_3", "Add an entry with invalid type");
    // Create an entry with invalid type
    csv_initEntry(&entry);
    csv_parseEntry(&entry, "68765432L;Jane;Doe;jane.doe2@example.com;Her street, 15;08500;12/01/1995", "INVALID_TYPE");                            
    if (fail_all) {
        failed = true;
    } else {
        // Add the entry
        error = api_addDataEntry(&data, entry);
        if (error != E_INVALID_ENTRY_TYPE) {
            failed = true;
            passed = false;
        }
    }
    end_test(test_section, "PR1_EX2_3", !failed);
    // Free memory
    csv_freeEntry(&entry);
    
    /////////////////////////////
    /////  PR1 EX2 TEST 4  //////
    /////////////////////////////
    failed = false;
    start_test(test_section, "PR1_EX2_4", "Add a person entry with invalid format");
    // Create an entry with invalid number of fields
    csv_initEntry(&entry);
    csv_parseEntry(&entry, "PERSON;68765432L;Jane;Doe;jane.doe2@example.com;Her street, 15;08500", NULL);                            
    if (fail_all) {
        failed = true;
    } else {
        error = api_addDataEntry(&data, entry);
        if (error != E_INVALID_ENTRY_FORMAT) {
            failed = true;
            passed = false;
        }
    }
    end_test(test_section, "PR1_EX2_4", !failed);
    
    // Free memory
    csv_freeEntry(&entry);
    
    
    /////////////////////////////
    /////  PR1 EX2 TEST 5  //////
    /////////////////////////////
    failed = false;
    start_test(test_section, "PR1_EX2_5", "Add a geoposition entry with invalid format");
    // Create an entry with invalid number of fields
    csv_initEntry(&entry);
    csv_parseEntry(&entry, "GEOLOCATION;87654321K;15/10/2021;13:41;41.3870;2.1698;Extra comment", NULL);
    if (fail_all) {
        failed = true;
    } else {
        error = api_addDataEntry(&data, entry);
        if (error != E_INVALID_ENTRY_FORMAT) {
            failed = true;
            passed = false;
        } 
    }
    end_test(test_section, "PR1_EX2_5", !failed);
    // Free memory
    csv_freeEntry(&entry);

    /////////////////////////////
    /////  PR1 EX2 TEST 6  //////
    /////////////////////////////
    failed = false;
    start_test(test_section, "PR1_EX2_6", "Add a duplicated person");
    // Create an entry 
    csv_initEntry(&entry);
    csv_parseEntry(&entry, "PERSON;68765432L;Jane;Doe;jane.doe2@example.com;Her street, 15;08500;12/01/1995", NULL);
    
    if (fail_all) {
        failed = true;
    } else {
        // Insert once to ensure it is present
        api_addDataEntry(&data, entry);
        // Try to insert it again
        error = api_addDataEntry(&data, entry);
        if (error != E_DUPLICATED_ENTRY) {
            failed = true;
            passed = false;
        }         
    }
    end_test(test_section, "PR1_EX2_6", !failed);
    // Free memory
    csv_freeEntry(&entry);
    
    /////////////////////////////
    /////  PR1 EX2 TEST 7  //////
    /////////////////////////////
    failed = false;
    start_test(test_section, "PR1_EX2_7", "Add a duplicated geoposition");
    // Create an entry 
    csv_initEntry(&entry);
    csv_parseEntry(&entry, "GEOLOCATION;87654321K;15/10/2021;13:41;41.3870;2.1698", NULL);
    if (fail_all) {
        failed = true;
    } else {
        // Insert once to ensure it is present
        api_addDataEntry(&data, entry);
        // Try to insert it again
        error = api_addDataEntry(&data, entry);
        if (error != E_DUPLICATED_ENTRY) {
            failed = true;
            passed = false;
        }         
    }
    end_test(test_section, "PR1_EX2_7", !failed);
    // Free memory
    csv_freeEntry(&entry);
    
    /////////////////////////////
    /////  PR1 EX2 TEST 8  //////
    /////////////////////////////
    failed = false;
    start_test(test_section, "PR1_EX2_8", "Remove all data");
    
    // Create a person entry 
    csv_initEntry(&entry);
    csv_parseEntry(&entry, "PERSON;87654321K;Jane;Doe;jane.doe2@example.com;Her street, 15;08500;12/01/1995", NULL);
    
    // Create a geodata entry     
    csv_initEntry(&entry2);
    csv_parseEntry(&entry2, "GEOLOCATION;87654321K;15/10/2021;13:41;41.3870;2.1698", NULL);
    if (fail_all) {
        failed = true;
    } else {
        // Ensure we cannot insert them    
        if (api_addDataEntry(&data, entry) != E_DUPLICATED_ENTRY || api_addDataEntry(&data, entry2) != E_DUPLICATED_ENTRY) {
            failed = true;
            passed = false;
        } else {
            // Remove all data
            api_freeData(&data);
          
            // Try to insert again
            if (api_addDataEntry(&data, entry) != E_SUCCESS || api_addDataEntry(&data, entry2) != E_SUCCESS) {
                failed = true;
                passed = false;
            }
        }
    }
    end_test(test_section, "PR1_EX2_8", !failed);
    // Free memory
    csv_freeEntry(&entry);    
    csv_freeEntry(&entry2);

    return passed;
}

// Run all tests for Exercice 3 of PR1
bool run_pr1_ex3(tTestSection* test_section, const char* input) {
    tApiData data;
    tApiError error;
    tCSVEntry entry;
    tCSVEntry person;
    tCSVData geoData;
    bool passed = true, failed = false;
    bool fail_all = false;
    
    // Load basic data to the API
    if (api_initData(&data) != E_SUCCESS) {
        fail_all = true;
    }    
    if (!fail_all && api_loadData(&data, input, true) != E_SUCCESS) {
        fail_all = true;
    }
     
    /////////////////////////////
    /////  PR1 EX3 TEST 1  //////
    /////////////////////////////
    failed = false;
    start_test(test_section, "PR1_EX3_1", "Find an exixting person");
    if (fail_all) {
        failed = true;
    } else {
        // Create a person entry to ensure it exists
        csv_initEntry(&entry);
        csv_parseEntry(&entry, "PERSON;87654321K;Jane;Doe;jane.doe2@example.com;Her street, 15;08500;12/01/1995", NULL);
        api_addDataEntry(&data, entry);
        error = api_findPerson(&data, "87654321K", &person);
        if (error != E_SUCCESS || csv_numFields(person) != 7) {
            failed = true;
        }
        // Free memory
        csv_freeEntry(&entry);
        csv_freeEntry(&person);
        
    }
    end_test(test_section, "PR1_EX3_1", !failed);
    
    /////////////////////////////
    /////  PR1 EX3 TEST 2  //////
    /////////////////////////////
    failed = false;
    start_test(test_section, "PR1_EX3_2", "Find a non exixting person");
    if (fail_all) {
        failed = true;
    } else {
        error = api_findPerson(&data, "00000000L", &person);
        if (error != E_PERSON_NOT_FOUND) {
            failed = true;
        }
    }
    end_test(test_section, "PR1_EX3_2", !failed);
    
    /////////////////////////////
    /////  PR1 EX3 TEST 3  //////
    /////////////////////////////
    failed = false;
    start_test(test_section, "PR1_EX3_3", "Get geoplocation from an exixting person");
    if (fail_all) {
        failed = true;
    } else {
        error = api_getPersonGeolocation(&data, "87654321K", &geoData);
        if (error != E_SUCCESS) {
            failed = true;
        }
        // Free memory    
        csv_free(&geoData);
    }
    end_test(test_section, "PR1_EX3_3", !failed);
    
    /////////////////////////////
    /////  PR1 EX3 TEST 4  //////
    /////////////////////////////
    failed = false;
    start_test(test_section, "PR1_EX3_4", "Get geoplocation from a non exixting person");
    if (fail_all) {
        failed = true;
    } else {
        error = api_getPersonGeolocation(&data, "00000000L", &geoData);
        if (error != E_PERSON_NOT_FOUND) {
            failed = true;
        }
    }
    end_test(test_section, "PR1_EX3_4", !failed);
    
    /////////////////////////////
    /////  PR1 EX3 TEST 5  //////
    /////////////////////////////
    failed = false;
    start_test(test_section, "PR1_EX3_5", "Remove an exixting person");
    if (fail_all) {
        failed = true;
    } else {
        error = api_removePerson(&data, "87654321K");
        if (error != E_SUCCESS) {
            failed = true;
        } else {
            error = api_getPersonGeolocation(&data, "87654321K", &geoData);
            if (error != E_PERSON_NOT_FOUND) {
                failed = true;
            }        
        }
    }
    end_test(test_section, "PR1_EX3_5", !failed);
    
    /////////////////////////////
    /////  PR1 EX3 TEST 6  //////
    /////////////////////////////
    failed = false;
    start_test(test_section, "PR1_EX3_6", "Remove a non exixting person");
    if (fail_all) {
        failed = true;
    } else {
        if (error != E_PERSON_NOT_FOUND) {
            failed = true;
        }
    }
    end_test(test_section, "PR1_EX3_6", !failed);
    
    return passed;
}