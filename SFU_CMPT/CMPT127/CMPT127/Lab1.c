//
//  Lab1.c
//  CMPT127
//
//  Created by June Kim on 2016-06-04.
//  Copyright © 2016 June Kim. All rights reserved.
//

#include "Lab1.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void printTriple(float value) {
    int trunk = floor(value);
    int mid = round(value);
    int ceiling = ceil(value);
    printf("%d %d %d\n", trunk, mid, ceiling);
}

int t3() {
    float value = 0;
    scanf( "%f", &value );
    int trunk = floor(value);
    int mid = round(value);
    int ceiling = ceil(value);
    printf("%d %d %d\n", trunk, mid, ceiling);
    return 0;
}

int t4(){
    float value = 0;
    int result = scanf( "%f", &value );
    if (result == 1) {
        printTriple(value);
    } else {
        printf("scanf error: (%d)\n", result);
    }
    return 0;
}

int t5() {
    float value = 0;
    while (scanf( "%f", &value ) != EOF) {
        //if blank, break;
        printTriple(value);
    }
    printf("Done.\n");
    return 0;
}

int t6() {
    float value = 0;
    float min = 100001;
    float max = -100001;
    float mean = 0;
    float counter = 0;
    float runningSum = 0;
    //  the arithmetic mean of all the values seen
    while (scanf( "%f", &value ) != EOF) {
        if (value > max) max = value;
        if (value < min) min = value;
        counter++;
        runningSum += value;
    }
    mean = runningSum/counter;
    
    printf("%.2f %.2f %.2f\n", min, max, mean);
    
    return 0;
}

void printHashLine(int hashes) {
    for (int i = 0; i < hashes; i++) {
        printf("#");
    }
}

int t7() { //Horizontal graph
    //input arbitrary number of positive integer values from stdin
    //output exactly one line of # per input value
    //zero should generate a newline character.
    //Ignore empty lines
    
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
    
    return 0;
    
}


void printHashDotHash(int width) {
    if (width == 1) {
        printf("#");
        return;
    }
    for (int i = 0; i < width; i++) {
        if (i == 0 || i == width - 1) {
            printf("#");
            continue;
        }
        printf(".");
    }
}

int t8() { //Pyramid Projection 1
    /*
     Read a line containing three positive integer values greater than 0 from stdin. The values are separated by one or more spaces.
     The input is guaranteed to be well-formed.
     The values represent the width (x dimension), breadth (y dimension) and height (z dimension) of a symmetrical rectangular-based pyramid, respectively. The height is measured perpendicularly from the base of the pyramid.
     All values will be in the range [1..50].
     On standard output, render a view from above the pyramid, showing its rectangular base, i.e., the projection of the pyramid onto the plane z=0. In this view, x increases from left to right, and y increases from bottom to top.
     Draw the outline of the pyramid with the '#' character. The outline must approximate the pyramid's boundary as shown in the examples below and described in the next two requirements.
     The top and bottom rows shall be drawn with exactly width '#' characters.
     For every remaining text row, either one or two '#' characters shall be drawn, covering the left-most and right-most position on that row intersected by the edge of the pyramid,
     Any non-boundary area inside the shape must be filled with the '.' character.
     */
    int width = 0; //left right
    int breadth = 0; //up down
    
    char *line = NULL;
    size_t size;
    char *pch;
    getline(&line, &size, stdin);
    pch = strtok (line, " ,.-");
    int value = atoi(pch);
    width = value;
    pch = strtok (NULL, " ,.-");
    value = atoi(pch);
    breadth = value;
    
    if (breadth == 1) {
        printHashLine(width);
        printf("\n");
        return 0;
    } else if (breadth == 2) {
        printHashLine(width);
        printf("\n");
        printHashLine(width);
        printf("\n");
        return 0;
    }
    printHashLine(width);
    printf("\n");
    for (int i = 0; i < breadth-2; i++) {
        printHashDotHash(width);
        printf("\n");
    }
    printHashLine(width);
    printf("\n");

    return 0;
}

void printBase(int x) {
    printHashLine(x);
}

void printBody() {
    
}

int t9() {
    /*
     The Pyramid
     showing its triangular side
     the projection of the pyramid onto the plane y=0. 
     x increases from left to right
     z increases from bottom to top
     
     The base: '#' characters
     The tip: every character position that intersects the boundary of the pyramid
     
     For the rest: either one or two '#' characters shall be drawn, covering the left-most and right-most position on that row intersected by the edge of the pyramid, as shown in the shaded regions in this image of a pyramid of width==6, breadth==6, height==4:
     Each line should be as few characters as possible:the final '#' character on each line should be immediately followed by a newline.
     */
    
    //
    
    int width = 0;
    int height = 0;
    
    char *line = NULL;
    size_t size;
    char *pch;
    getline(&line, &size, stdin);
    pch = strtok (line, " ,.-");
    width = atoi(pch);
    pch = strtok (NULL, " ,.-");
    pch = strtok (NULL, " ,.-");
    height = atoi(pch);
    
    
    
    /* major hint
     // find x-coordinates of pyramid edges on the j'th row
     // where x is the pyramid width, z is the pyramid height,
     */
    for (int j = height-1; j > 0; j--) {
        int left = floor( j * (width/(2.0*height)) );
        int right = ceil( (width-1) + -j * (width/(2.0*height)));
        
        for (int i = 0; i <= right; i++) {
            if (i == left || i == right) {
                printf("#");
            } else if (i < left) {
                printf(" ");
            } else {
                if (j == height-1) {
                    printf("#");
                } else {
                    printf(".");
                }
            }
        }
        printf("\n");
    }
    
    
    printBase(width);
    
    return 0;
}


void testLab1() {
    t9();
}
