//
//  main.c
//  OneTwoFive
//
//  Created by June Kim on 2016-05-17.
//  Copyright © 2016 June Kim. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>


void printArray(int *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int* create_array( int length) {
    int *array = (int *)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        array[i] = i;
    }
    return array;
}


// Post: Returns 1 iff target is in arr[0..len-1], 0 otherwise.
int RecursiveBinarySearch(int arr[], int len, int target) {
    if (len == 0) return 0;
    int mid = len/2;
    if (target < arr[mid]){
        return RecursiveBinarySearch(arr, mid, target);
    } else {
        // the || operator short-circuits.
        return target == arr[mid] || RecursiveBinarySearch(arr+mid+1, len-mid-1, target);
    }
    
}

int IterativeBinarySearch(int arr[], int len, int target) {
    int first = 0;
    int last = len-1;
    while (first <= last) {
        // Assert:
        // if the target is in the array, then it is between first and last
        // all elements before the first index are smaller than target
        // all elements after the last index are larger than target
        int mid = (first+last) / 2;
        if (target == arr[mid]) {
            return 1;
        }
        //map both first and last to be a function of isAfter
        int isAfter = target > arr[mid];
        //if (target > arr[mid]) first = mid+1
        first = isAfter * (mid + 1) + (1-isAfter) * first;
        //if (target < arr[mid]) last = mid-1
        last = (1-isAfter) * (mid - 1) + isAfter * last;
        
    }
    
    return -1;
}
void testSearch(int arraySize) {
    
    int *sortedArray = create_array(arraySize);
    
    printArray(sortedArray, arraySize);
    
    for (int i = 1; i < 10000000; i *= 2) {
        printf("i: %d \n", i);
        
        printf("Recursive Search result: %d\n", RecursiveBinarySearch(sortedArray, arraySize, i));
        printf("Iterative Search result: %d\n", IterativeBinarySearch(sortedArray, arraySize, i));
    }
    
    
}
int main(int argc, const char * argv[]) {
    testSearch(10);
    testSearch(100);
    testSearch(1000);
    testSearch(10000);
    testSearch(100000);
    testSearch(1000000);
    return 0;
}
