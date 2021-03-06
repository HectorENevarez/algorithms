#include <iostream>
#include <unistd.h>
#include <string.h>

// project includes
#include "algorithms.h"

static void _print_help(){

}

int main(int argc, char *argv[]){
    
    // sanity check
    if (argc == 1){
        printf("You must specify an algorithm to run, printing help menu\n\n");
        _print_help();
        return 0; // exit early
    }
    
    // Merge Sort algorithm
    if (!strcmp(argv[1], "mergesort")){
        mergesort_start();
    }

    // largest complete subtree algorithm
    if (!strcmp(argv[1], "complete-subtree")){
        complete_subtree_init();
    }

    // Find index in sorted array algorithm
    if (!strcmp(argv[1], "index-in-array")){
        index_in_array_start();
    }

    else {
        printf("The algorithm specific is not found, printing help menu\n");
        _print_help();
    }

    return 0;
}