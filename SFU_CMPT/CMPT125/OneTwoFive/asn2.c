//
//  asn2.c
//  OneTwoFive
//
//  Created by June Kim on 2016-06-04.
//  Copyright © 2016 June Kim. All rights reserved.
//

#include "asn2.h"
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void printArray(int *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

//description: sorts the array in O(n^2) time in worst-case
//precondition: the input array may not be sorted
//postcondition: the array has been sorted in ascending order
void bubbleSort(int *array, int length) {
    //array is not sorted up to the unsorted index.
    int unsortedIndex = length;
    //keep sorting the array until the unsorted index reaches zero.
    while (unsortedIndex != 0) {
        //for each element from the beginning to the end of where it is unsorted
        for (int i = 0; i < unsortedIndex - 1; i++) {
            //compare the element to its next neighbor
            if (array[i] > array[i+1]) {
                //if the element is bigger, swap.
                int swapTemp = array[i+1];
                array[i+1] = array[i];
                array[i] = swapTemp;
                //the ith element has taken place of its next neighbor
            } else {
                //if the element is not bigger, do nothing.
            }
            //the ith element is now smaller than the (i+1)th.
        }
        //decrement unsorted index to indicate that the last element of this pass is the largest
        //all elements beyond the unsorted index is sorted.
        unsortedIndex--;
        //continue until the unsorted index reaches zero.
    }
}

//description: sorts the array in place in O(n^2) time in worst case
//precondition: the input array may not be sorted
//postcondition: the array has been sorted in ascending order
void insertionSort(int *array, int length) {
    //one element is sorted on its own
    for (int sortedIndex = 1; sortedIndex < length; sortedIndex++) {
        //the element to be inserted is to the right of the sorted index
        int toBeInserted = array[sortedIndex];
        //from the beginning of the array up to the sorted index,
        for (int insertPoint = 0; insertPoint < sortedIndex; insertPoint++) {
            //compare the element to be inserted against each element
            if (toBeInserted < array[insertPoint]) {
                //and if it is less, shift all the elements from the index up to the sorted index to its right and insert the element
                for (int j = sortedIndex; j > insertPoint; j--) {
                    array[j] = array[j-1];
                }
                array[insertPoint] = toBeInserted;
                break;
            } else {
                //but if it is not less, then keep it in its place
                //if nothing shifted, then the element to be inserted is in its sorted place
            }
            //loop invariant: the element inserted is now sorted between the beginning of the array and the index
        }
    }
    //loop invariant: the array is sorted up to the sorted index.
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




void asn2Test() {
    //bubbleSort(randomArray, arraySize);
    //insertionSort(randomArray, arraySize);
    
    printf("enter 'b' for bubble sort, 'i' for insertion sort");
    char algorithm = getchar();
    int arraySize;
    printf("enter array size");
    scanf("%d",&arraySize);
    printf("enter 's' for sorted, 'v' for reverse sorted, or 'r' for random");
    char arrayType = getchar();
    int* theArray = create_array(arrayType, arraySize);
    
    if (algorithm == 'b') {
        bubbleSort(theArray, arraySize);
    } else if (algorithm == 'i') {
        insertionSort(theArray, arraySize);
    }
    
    
    
    
}

int main() {
    asn2Test();
    
    return 0;
}