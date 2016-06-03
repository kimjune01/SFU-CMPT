//
//  floatlib.c
//  CMPT295
//
//  Created by June Kim on 2016-06-02.
//  Copyright © 2016 June Kim. All rights reserved.
//

#include "floatlib.h"
#include <stdio.h>
#include <math.h>

//a bit16 floating point number with m = 8
typedef unsigned bit16;


//use the bitwise operators
//and, or, not, xor, shift-right, and shift-left
// & | ! ^ >> <<
//use “==” and “!=” but none of the other relational operators
void printhex(bit16 x){
    printf("%.4x  ", x);
}

bit16 construct(unsigned sign, unsigned expon, unsigned signif) {
    bit16 new16 = 0;
    
    new16 += sign *  0b1000000000000000;
    new16 += expon * 0b0000000010000000;
    new16 += signif;
    
    return new16;
}

unsigned extractSign(bit16 encoding) {
    unsigned sign = encoding & 0b1000000000000000;
    sign >>= 15;
    return sign;
}

unsigned extractExponent(bit16 encoding) {
    unsigned exponent = encoding & 0b0111111110000000;
    exponent >>= 7;
    return exponent;
}

unsigned extractSignificand(bit16 encoding) {
    return encoding & 0b0000000001111111;
}

bit16 fp_add(bit16 x, bit16 y){ //non-negative x and y
    if (x == 0) return y;
    if (y == 0) return x;
    unsigned xSign = extractSign(x);
    unsigned ySign = extractSign(y);
    unsigned xExponent = extractExponent(x);
    unsigned yExponent = extractExponent(y);
    unsigned xSignificand = extractSignificand(x) + 0b10000000;
    unsigned ySignificand = extractSignificand(y) + 0b10000000;
    

    unsigned delta = 0;
    
    if (xExponent < yExponent) {
        delta = yExponent - xExponent;
        xExponent += delta;
        xSignificand >>= delta;
    } else {
        delta = xExponent - yExponent;
        yExponent += delta;
        ySignificand >>= delta;
    }
    
    unsigned newSignificand = xSignificand + ySignificand;

    if (newSignificand == 0) {
        return 0;
    }
    
    unsigned mostSignificand = newSignificand & 0b00100000000; //greater than 2
    mostSignificand >>= 8;

    while (mostSignificand == 1) {
        yExponent++;
        newSignificand >>= 1;
        mostSignificand = newSignificand & 0b00100000000; //greater than 2
        mostSignificand >>= 8;
    }

    unsigned secondSignificand = newSignificand & 0b00010000000;
    secondSignificand >>= 7;
    
    while (secondSignificand == 0) {
        yExponent --;
        newSignificand <<= 1;
        secondSignificand = newSignificand & 0b00010000000;
        secondSignificand >>= 7;
    }
    
    unsigned newSign = extractSign(newSignificand);
    unsigned newExponent = yExponent;
    newSignificand = (newSignificand & 0b1111111);
    
    bit16 newSum = construct(newSign, newExponent, newSignificand);
    
    
    return newSum;
}

bit16 SM_ADD(bit16 x, bit16 y){ //works with both positive and negative
    
    
    return 0;
}

void print16(bit16 encoding) {
    unsigned sign = extractSign(encoding);
    float signPart = powf(-1, sign);
    unsigned exponent = extractExponent(encoding);
    float powerPart = powf(2, exponent - pow(2, 7) + 1);
    unsigned significand = extractSignificand(encoding);
    float fractionPart = significand * pow(2, -7);
    float decoded = signPart * powerPart * (1 + fractionPart);
    printf("print16: %f  ", decoded);
    printf("0x");
    printhex(encoding);
    printf("%u %u %u\n", sign, exponent, significand);
    
    
}



void printSignificand (unsigned significand) {
    float runningSum = 0;
    while (significand >= 128) {
        runningSum += 1;
        significand -= 128;
    }

    for (int i = 6; i > 0; i--) {
        int twoPower = powf(2, i);
        int leadingOne = significand/twoPower == 1;
        if (leadingOne) {
            float addition = powf(0.5, 7-i);
            runningSum += addition;
            significand -= twoPower;
        }
        // i = 6 -> 0.5, i = 5 -> 0.25
            //0.5^(7-i)
        
        
        //separate most significant
        //right shift by one
    }
    
    printf(" %f \n", runningSum);
    
    return;
}