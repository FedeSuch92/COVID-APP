#include <assert.h>
#include <string.h>
#include "test.h"
#include "test_pr1.h"

// Define default test data
const char* test_data_str = "PERSON;87654321K;John;Smith;john.smith@example.com;My street, 25;08001;30/12/1980\n" \
                            "PERSON;98765432J;Jane;Doe;jane.doe@example.com;Her street, 5;08500;12/01/1995\n" \
                            "GEOLOCATION;87654321K;15/10/2021;13:41;41.3870;2.1698\n" \
                            "GEOLOCATION;87654321K;15/10/2021;13:45;41.3870;2.1695\n" \
                            "GEOLOCATION;98765432J;15/10/2021;13:50;41.3871;2.1697\n" \
                            "GEOLOCATION;87654321K;15/10/2021;13:50;41.3871;2.1697\n";

// Run all available tests
void testSuite_run(tTestSuite* test_suite, const char* input) {
    const char* default_input = "default_data.csv";
    FILE *fout;
    const char* filename;
    
    assert(test_suite != NULL);
    
    // Load the README.txt file
    testSuite_load_learner(test_suite, "../README.txt");
    
    // If no file is provided, use default data
    if (input == NULL) {
        filename = default_input;
        fout = fopen(filename, "w");
        assert(fout != NULL);
        fwrite(test_data_str, strlen(test_data_str), 1, fout);
        fclose(fout);
    } else {
        filename = input;
    }

    // Run tests for PR1
    run_pr1(test_suite, filename);
}

