//
//  SelectionSort.c
//  OneTwoFive
//
//  Created by June Kim on 2016-06-05.
//  Copyright © 2016 June Kim. All rights reserved.
//

#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdio.h>

void printArray(int *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int* create_array(char category, int length) {
    int *array = (int *)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        array[i] = i;
    }
    if (category == 's') {
        return array;
    }
    if (category == 'v') {
        for (int i = 0; i < length; i++) {
            array[i] = length-i;
        }
        return array;
    }
    if (category == 'r') {
        time_t t;
        srand((unsigned) time(&t));
        size_t i;
        
        for (i = 0; i < length - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (length - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
        return array;
    }
    return array;
}

//magic of the internet. recursive max
int getMaxIndex(int arr[], int m) {
    int maxIndex;
    if (m == 0) return m;
    maxIndex = getMaxIndex(arr, m-1);
    if (arr[m] > arr[maxIndex]) return m;
    return maxIndex;
    
}

//description: a recursive selection sort that runs in O(n^2)
//precondition: the array is not sorted from index 0 up to len-1
//postcondition: the array is sorted
void SelectionSort(int arr[], int len) {
    //trivial case. an array of length 1 is already sorted
    if (len == 1) {
        return;
    }
    //select the maximum
    int maxIndex = getMaxIndex(arr, len-1);
    //swap the maximum with the last element if needed
    if (maxIndex != len-1) {
        //temporarily store the last element
        int lastElement = arr[len-1];
        //place the max element in its place
        arr[len-1] = arr[maxIndex];
        //place the last element in the void
        arr[maxIndex] = lastElement;
    }
    //now that the last element is the greatest of the array,
    //make the next last element the greatest of its array.
    SelectionSort(arr, len-1);
    
}

void testSelectionSort() {
    int arraySize = 10;
    int* randomArray = create_array('r', arraySize);
    printf("Unsorted array: \n");
    printArray(randomArray, arraySize);
    SelectionSort(randomArray, arraySize);
    printf("Selection Sorted array: \n");
    printArray(randomArray, arraySize);
    
    arraySize = 50;
    randomArray = create_array('r', arraySize);
    printf("Unsorted array: \n");
    printArray(randomArray, arraySize);
    SelectionSort(randomArray, arraySize);
    printf("Selection Sorted array: \n");
    printArray(randomArray, arraySize);
    
}

int main() {
    testSelectionSort();
    return 0;
}