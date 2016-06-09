//
//  Lab2.c
//  CMPT127
//
//  Created by June Kim on 2016-06-04.
//  Copyright © 2016 June Kim. All rights reserved.
//

#include "Lab2.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>


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

int count() { //main() in count.c
    unsigned long chars = 0;
    unsigned long lines = 0;
    unsigned long words = 0;
    int boolean= 0;
    int counter;
    while ( (counter = getchar()) != EOF){
        chars++;
        if (counter == ' '){
            boolean=0;
        } else if(boolean==0){
            words++;
            boolean=1;
        }
        if (counter=='\n'){
            lines++;
        }
    }
    printf( "%lu %lu %lu\n", chars, words, lines );
    
    return 0;
}

int compare(char* oneWord, char* otherWord) {
    char oneWordCopy[128];
    strcpy(oneWordCopy, oneWord);
    char otherWordCopy[128];
    strcpy(otherWordCopy, otherWord);
    
    for (int i = 0; i < 128; i++) {
        if (oneWordCopy[i] != otherWordCopy[i]) {
            return 0;
        }
        if (oneWordCopy[i] == 0) {
            return 1;
        }
    }
    return 1;
}

char *changewords_1 (char *sentence, char *find, char *replace)
{
    char *dest = malloc (strlen(sentence)-strlen(find)+strlen(replace)+1);
    char *destptr = dest;
    
    *dest = 0;
    
    while (*sentence)
    {
        if (!strncmp (sentence, find, strlen(find)))
        {
            strcat (destptr, replace);
            sentence += strlen(find);
            destptr += strlen(replace);
        } else
        {
            *destptr = *sentence;
            destptr++;
            sentence++;
        }
    }
    *destptr = 0;
    return dest;
}

char *replace_str(char *str, char *orig, char *rep, int start)
{
    static char temp[4096];
    static char buffer[4096];
    char *p;
    
    strcpy(temp, str + start);
    
    if(!(p = strstr(temp, orig)))  // Is 'orig' even in 'temp'?
        return temp;
    
    strncpy(buffer, temp, p-temp); // Copy characters from 'temp' start to 'orig' str
    buffer[p-temp] = '\0';
    
    sprintf(buffer + (p - temp), "%s%s", rep, p + strlen(orig));
    sprintf(str + start, "%s", buffer);
    
    return str;
}

char* concat(char *s1, char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);//+1 for the zero-terminator
    //in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}


int censor( int argc, char* argv[] ) { //main in letterfreq.c
    //load censored words into memory
    char* censoredWords[] = {};
    for (int i = 0; i < argc - 1; i++) {
        censoredWords[i] = argv[i+1];
    }
    
    char cursor;
    
    char * pch;
    char word[128];
    char choppedWord[128];
    char delimiter;
    int charCounter = 0;
    //Said Hamlet to Ophelia, Said Hamlet to Ophelia,
    //Said Hamlet to Ophelia,
    //Said Hamlet to Ophelia,
    while ( (cursor = getchar()) != EOF){
        word[charCounter++] = cursor;
        //store word until delimiter
        if (cursor == ' ' || cursor == '.' || cursor == ',' || cursor == '-' || cursor == 'n') {
            //detect word
            for (int i = 0; i < charCounter-1; i++) {
                choppedWord[i] = word[i];
            }
            delimiter = cursor;
            //if word matches
            int match = 0;
            for (int i = 0; i < argc - 1; i++) {
                if (strcmp(choppedWord, censoredWords[i]) == 0) {
                    match = 1;
                    break;
                }
            }
            if (match) {
                //print CENSORED + delimiter
                printf("CENSORED%c", delimiter);
            } else {
                printf("%s%c", choppedWord, delimiter);
            }
            //purge words and counter
            charCounter = 0;
            for (int i = 0; i < 128; i++) {
                choppedWord[i] = '\0';
                word[i] = '\0';
            }
        }
    }
    
    return 0;
}

/*    
 char *line = NULL;
 size_t size;
 char *pch;
 while (getline(&line, &size, stdin) != EOF) {
 pch = strtok (line, " ,.-");
 if (pch[0] == '\n' || pch[0] == ' ') {
 continue;
 }
 while (pch != NULL){
 //pch[strlen(pch)-1] = 0;
 int value = atoi(pch);
 printHashLine(value);
 pch = strtok (NULL, " ,.-");
 if (pch != NULL) {
 if (pch[0] == '\n' || pch[0] == ' ') {
 continue;
 }
 
 }
 printf("\n");
 
 }
 }
 */

int letterFrequency() {
    /*
     Write a program that calculates the frequency of letter occurrences in text.
     Read ASCII text from standard input.
     On reaching EOF, print to stdout the normalized frequency of occurrence for each letter a-z that appeared in the input, one per line, in alphabetical order using the format produced by
     printf( "%c %.4f\n", letter, freq);
     Letters that occur zero times should not appear in the output.
     Characters other than lower and upper case letters should be ignored.
     Lower and upper case instances count as the same letter, e.g. 'a' and 'A' are both reported for the letter 'a' on the output.
     The frequencies reported should sum to approximately 1 (with a little slack for accumulation of printf rounding errors).
     */
    return 0;
}

int t9_2() { //verticalgraph.c
    /*
     Read integer values from stdin, separated by one or more spaces or newlines, until reaching EOF.
     The input is guaranteed to be well-formed.
     The input contains no more than 80 values.
     On standard output, render a simple vertical column graph representation of the input values, in order left to right, using hash '#' characters as shown in the examples below. The number of hashes printed in each column should be equal to the corresponding input value.
     The area above a completed column should be filled with space characters.
     Ignore empty lines. Do not output a column for an empty line.
     The entire graph must end with a newline character.
     */
     
    return 0;
}

int InRectangle( float pt[2], float rect[4] ) { //inrect.c
    
    return 0;
}

int inRectangleTest() {
    // define a rectangle from (1,1) to (2,2)
    float rect[4] = {1.0, 1.0, 2.0, 2.0 };
    
    // define a point that is inside the rectangle
    float p_in[2] = { 1.5, 1.5 };
    
    // define a point that is outside the rectangle
    float p_out[2] = {2.5, 0.5};
    
    // define a point that is on the edge of the rectangle
    float p_edge[2] = {1.0, 1.0};
    
    // InRectangle() should return 0 (false) for points that are NOT in
    // the rectangle, and non-zero (true) for points that are in the
    // rectangle. Points on the edge are considered *in* the rectangle.
    
    // test 1
    if( InRectangle( p_in, rect ) == 0 )
    {
        puts( "error: should return true for p_in." );
        return 1; // indicate error
    }
    
    // test 2
    if( InRectangle( p_out, rect ) != 0 )
    {
        puts( "error: should return false for p_out." );
        return 1; // indicate error
    }
    
    // test 3
    if( InRectangle( p_edge, rect ) == 0 )
    {
        puts( "error: should return true for p_edge." );
        return 1; // indicate error
    }
    return 0;
}

void printArray(int arr[], unsigned int len) {
    printf("print array of length %d: \n", len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int containsTest( int argc, char* argv[ ] ){
    // Write a program called "contains" that takes two text strings as arguments
    // and prints "true" followed by a newline if the second string is entirely
    // contained within the first, or "false" followed by a newline otherwise.
    if ( argc != 3 ) // yes 3! argv[0] is the program name
        // printf( "I wanted 2 arguments\n" );
        printf("false\n");
    else {
        // The strings contain only ASCII characters and may be any length > 0 characters.
        // Strings in argv are always null-terminated.
        if ( (strlen(argv[1]) == 0) || (strlen(argv[2]) == 0) )
            printf("false\n");
        else {
            if ( contains(argv[1], argv[2]) )
                // result = 0;
                printf("true\n");
            else 
                printf("false\n");
        }
    }
    return 0;
}

void testLab2(){
    char* this = "this";
    char* that = "that";
    //
//    printf("compare this and that: %d\n", compare(this,that));
//    
//    printf("compare this and this: %d\n", compare(this, this));
    
//    char *testContainsInput[] = {"contains", "I have a really bad feeling about this", "bad feeling"};
//    containsTest(3, testContainsInput);
    
    //
    char* testInput[] = {"censor", "Ophelia"};
    censor(2, testInput);

    
//    inRectangleTest()
}