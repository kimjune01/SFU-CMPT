//
//  floatlib.c
//  CMPT295
//
//  Created by June Kim on 2016-06-02.
//  Copyright © 2016 June Kim. All rights reserved.
//

#include "floatlib.h"


//a bit16 floating point number with m = 8
typedef unsigned bit16;


//use the bitwise operators
//and, or, not, xor, shift-right, and shift-left
// & | ! ^ >> <<
//use “==” and “!=” but none of the other relational operators


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
    unsigned xSignificand = extractSignificand(x);
    unsigned ySignificand = extractSignificand(y);
    
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
    
    unsigned mostSignificand = newSignificand & 0b10000000;
    mostSignificand >>= 7;
    
    
    if (mostSignificand == 1) {
        
    } else {
        
    }
    
    
    
    return 0;
}

bit16 SM_ADD(bit16 x, bit16 y){ //works with both positive and negative
    
    
    return 0;
}