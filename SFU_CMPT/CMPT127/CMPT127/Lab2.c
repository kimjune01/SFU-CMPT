//
//  Lab2.c
//  CMPT127
//
//  Created by June Kim on 2016-06-04.
//  Copyright © 2016 June Kim. All rights reserved.
//

#include "Lab2.h"

void printArray(int arr[], unsigned int len);

int identical( int a[], int b[], unsigned int len ){ //identical.c
    int same = 1;
    
    for (int i = 0; i < len; i++){
        if (a[i] != b[i]){
            same = 0;
        }
        
    }
    return same;
}

void reverse( int arr[], unsigned int len ) { //reverse.c
    //in-place.
    if (len == 0 || len == 1) {
        return;
    }
    
    int frontCursor = 0;
    int rearCursor = len-1;
    
    while (frontCursor != rearCursor) {
        //swap
        int temp = arr[frontCursor];
        arr[frontCursor] = arr[rearCursor];
        arr[rearCursor] = temp;
        
        frontCursor++;
        rearCursor--;
        if (frontCursor - rearCursor == 1) {
            break;
        }
    }
    return;
}

int scrambled( unsigned int a[], unsigned int b[], unsigned int len ) {
    //compares the two arrays as a set in O(n)
    //the range of values = [0..99]
    
    //initialize an array of length 100
    int intListA[100] = {};
    for (int i = 0; i < len; i++) {
        intListA[a[i]]++;
    }

    int intListB[100] = {};
    for (int i = 0; i < len; i++) {
        intListB[b[i]]++;
    }

    for (int i = 0; i < 100; i++) {
        intListA[i] -= intListB[i];
        if (intListA[i] != 0) {
            return 0;
        }
    }
    
    return 1;
}

int contains( char* phrase, char* word ) { //contains.c
    //ascii
    //print true if the word is contained by the phrase
    
    const char* phraseCursor = phrase;
    const char* wordCursor = word;
    
    int wordLength = 0;
    while (wordCursor!= NULL && *wordCursor != '\0') {
        wordLength++;
        wordCursor++;
    }
    
    while (phraseCursor != NULL && *phraseCursor != '\0') {
        char currentPhraseChar = phraseCursor[0];
        
        wordCursor = word;
        
        char currentWordChar = wordCursor[0];
        if (currentPhraseChar == currentWordChar) {
            //first character matches. loop for word length
            int match = 1;
            for (int i = 0; i < wordLength; i++) {
                if (phraseCursor[i] != wordCursor[i]) {
                    match = 0;
                }
            }
            if (match) {
                printf("true\n");
                return 1;
            }
        }
        
        
        phraseCursor++;
    }
    printf("false\n");
    return 0;
}

int redirection() {
    /*
     counts the number of characters, words and lines read from standard input until EOF.
     Assume ASCII text of any length.
     Every byte counts as a character except EOF.
     Words are sequences of letters and the apostrophe.
     Lines are separated by newline characters ('\n').
     Characters beyond the final newline character will not be included in the line count.
     On EOF, printf( "%lu %lu %lu\n", charcount, wordcount, linecount );
     
     */
    return 0;
}

int t7_2() {
    
    return 0;
}

int t8_2() {
    
    return 0;
}

int t9_2() {
    
    return 0;
}

int t10_2() {
    
    return 0;
}

void printArray(int arr[], unsigned int len) {
    printf("print array of length %d: \n", len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void testLab2(){
    int array[] = {1, 2, 3, 4, 5, 6};
    int barry[] = {1, 2, 3, 4, 5, 6};
    unsigned int carry[] = {1, 2, 3, 4, 5, 6};
    unsigned int dairy[] = {1, 2, 3, 4, 5, 6};
//    printArray(array, 6);
//    reverse(array, 6);
//    printArray(array, 6);
    
//    printf("Do the two arrays contain the same elements?\n");
//    if(scrambled(carry, dairy, 6)) {
//        printf("Yes!\n");
//    } else {
//        printf("No.\n");
//        
//    }
    
    //
    char *walrusPhrase = "I have a really bad feeling about this";
    char *walrusWord = "bad feeling";
    
    char *hamletPhrase = "To be or not to be";
    char *hamletWord = "That is the question";
    
    printf("Does this phrase contain that word? \n");
    if (contains(hamletPhrase, hamletWord)) {
        printf("Yes!\n");
    } else {
        printf("No.\n");
    }
    
}