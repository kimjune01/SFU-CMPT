//
//  floatlib.h
//  CMPT295
//
//  Created by June Kim on 2016-06-02.
//  Copyright © 2016 June Kim. All rights reserved.
//

#ifndef floatlib_h
#define floatlib_h

#include <stdio.h>

typedef unsigned bit16;

bit16 construct(unsigned sign, unsigned expon, unsigned signif);
unsigned extractSign(bit16 encoding);
unsigned extractExponent(bit16 encoding);
unsigned extractSignificand(bit16 encoding);
bit16 fp_add(bit16 x, bit16 y);
void print16(bit16 encoding);
void printSignificand (unsigned significand);
bit16 SM_ADD(bit16 x, bit16 y);


#endif /* floatlib_h */
