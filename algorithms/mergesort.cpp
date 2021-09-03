#include <iostream>
#include <string.h>
#include <stdlib.h>  // rand
#include <time.h>
#include <math.h>    // ceil
 

// local includes
#include "mergesort.h"

// internally defined configurable parameters
#define MERGESORT_ARRAY_SIZE    11  // array size of array to be sorted
#define MAX_RAND_NUMBER         25  // max random value

// TODO: work on printing the tree
// prints the mergesort step by step
static void _print_merge_tree(int array[]){
    // at the lowest level calculate how many subarrays will be printed
    // take ceiling in order to account for subarrays with only one index
    // this will only happen on negative array sizes
    static int num_subarrays = ceil((float)MERGESORT_ARRAY_SIZE / 2);
    
    // subarray counter for printing newline to format
    static int subarrays_counter = 0;

    printf("[ %d %d]\n", array[0], array[1]);
    
}

static void _merge(int array[], int left, int mid, int right){
    int idx;
    
    int sub_array_one_size = mid - left + 1;
    int sub_array_two_size = right - mid;

    int left_array[sub_array_one_size] = {0};
    int right_array[sub_array_two_size] = {0};

    // split array and copy properly into right side
    for(idx = 0; idx < sub_array_one_size; idx++) left_array[idx] = array[left + idx];
    for(idx = 0; idx < sub_array_two_size; idx++) right_array[idx] = array[mid + 1 + idx];

    // starting indices of each array
    int sub_array_one_idx = 0;
    int sub_array_two_idx = 0;
    int merged_array_idx = left;

    // start the mergesort
    while (sub_array_one_idx < sub_array_one_size && sub_array_two_idx < sub_array_two_size){
        
        // if left is less than right
        if(left_array[sub_array_one_idx] <= right_array[sub_array_two_idx]){
            array[merged_array_idx] = left_array[sub_array_one_idx];
            sub_array_one_idx++;
        }
        // right less than left
        else{
            array[merged_array_idx] = right_array[sub_array_two_idx];
            sub_array_two_idx++;
        }
        merged_array_idx++; 
    }

    
    while (sub_array_one_idx < sub_array_one_size){
        array[merged_array_idx] = left_array[sub_array_one_idx];
        sub_array_one_idx++;
        merged_array_idx++;
    }

    while (sub_array_two_idx < sub_array_two_size){
        array[merged_array_idx] = right_array[sub_array_two_idx];
        sub_array_two_idx++;
        merged_array_idx++;
    }
    
    // print results of merge
    // _print_merge_tree(left_array);
    // _print_merge_tree(right_array);
}

static void _mergesort(int array[], int start, int end){
    if (start >= end) return; // return recursively

    int mid = start + (end - start) / 2; // find the middle of the array
    _mergesort(array, start, mid); // left side of array
    _mergesort(array, mid + 1, end); // right side of array
    _merge(array, start, mid, end); // merge
}

int mergesort_start(){
    // initialize array of chosen size
    int unsorted_array[MERGESORT_ARRAY_SIZE] = {0};
    int sorted_array[MERGESORT_ARRAY_SIZE] = {0};
    
    printf("printing unsorted array generated randomly\n[");
    
    srand(time(NULL)); // set a random seed for rand
    for (int idx = 0; idx < MERGESORT_ARRAY_SIZE; idx++){
        // obtain random value and insert into array
        int rand_val = rand() % MAX_RAND_NUMBER;
        unsorted_array[idx] = rand_val;

        // user print
        printf("%3d ", rand_val);
    }
    printf("]\n"); // formatter

    // begin the mergesort
    _mergesort(unsorted_array, 0, MERGESORT_ARRAY_SIZE - 1);

    // unecessary memcpy to store newly sorted unsorted array in sorted array variable
    memcpy(sorted_array, unsorted_array, sizeof(int) * MERGESORT_ARRAY_SIZE);

    printf("Printing sorted array:\n[");
    for (int idx = 0; idx < MERGESORT_ARRAY_SIZE; idx++) printf("%3d ", sorted_array[idx]);
    printf("]\n"); // formatter

    return 1;
}