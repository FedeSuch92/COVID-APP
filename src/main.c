#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"
#include "api.h"

typedef struct _AppArguments {
    char* app_name;
    char* out_file;    
    char* in_file;
    bool wait_on_exit;
} tAppArguments;

// Wait user key
void waitKey(tAppArguments parameters) {
    if (parameters.wait_on_exit) {
        printf("Press key to continue...");
        getchar();
    }
}

// Display help text
void help(const char* app_name) {
    printf("%s [--help] [--in <input_test_file>] [--out <output_file>] [--test-out <output_test_file>]\n", app_name);    
    printf("\t[%s] %s\n", "--help", "Show this help information.");
    printf("\t[%s] %s\n", "--no-wait", "Do not wait user key press on exit.");
    printf("\t[%s] %s\n", "--in", "Provide file with input test data in CSV format.");
    printf("\t[%s] %s\n", "--out", "Write the result of tests in a file in JSON format.");    
}

bool parseArguments(tAppArguments* arguments, int argc, char **argv) {
    int i;
    
    // Initialize the arguments
    arguments->app_name = NULL;
    arguments->out_file = NULL;    
    arguments->in_file = NULL;
    arguments->wait_on_exit = true;
    
    // Parse input arguments
    arguments->app_name = argv[0];
    for (i=1; i < argc; i += 2) {
        if (strcmp(argv[i], "--help") == 0) {
            help(argv[0]);
        }
        if (strcmp(argv[i], "--no-wait") == 0) {
            arguments->wait_on_exit = false;
        }
        if (strcmp(argv[i], "--in") == 0) {
            if (argc < i + 1) {
                help(argv[0]);
                return false;
            }
            arguments->in_file = argv[i+1];
        }
        if (strcmp(argv[i], "--out") == 0) {
            if (argc < i + 1) {
                help(argv[0]);
                return false;
            }
            arguments->out_file = argv[i+1];
        }
    }
    
    return true;
}

int main(int argc, char **argv)
{
    tAppArguments parameters;
    tTestSuite testSuite;
    
    // Parse input arguments
    if (!parseArguments(&parameters, argc, argv)) {
        printf("ERROR: Invalid input arguments");
        // Wait user to press a key to ensure error is shown
        waitKey(parameters);
        // Exit with error
        exit(EXIT_FAILURE);
    }
    
    // Initialize the test suite
    testSuite_init(&testSuite);
    
    // Run all tests
    testSuite_run(&testSuite, parameters.in_file);
    
    // Print test results
    testSuite_print(&testSuite);
    
    // Store test results
    if (parameters.out_file != NULL) {
        testSuite_export(&testSuite, parameters.out_file);
        printf("Restults stored in %s\n", parameters.out_file);
    }
    
    // Remove test suite data
    testSuite_free(&testSuite);    
    
    // Wait user to press a key to ensure results are shown
    waitKey(parameters);
    
	exit(EXIT_SUCCESS);
}
