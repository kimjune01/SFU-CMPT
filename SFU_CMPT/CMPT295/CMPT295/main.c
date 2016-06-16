//
//  main.c
//  CMPT295
//
//  Created by June Kim on 2016-06-02.
//  Copyright © 2016 June Kim. All rights reserved.
//

#include <stdio.h>
#include "floatlib.h"
#include "converter.h"
#include "converterAssembly.s"

void fp_add_test();
void converter_test();

int main(int argc, const char * argv[]) {
    
    converter_test();
//    fp_add_test();
    
    return 0;
}

void printhex(bit16 x){
    printf("%.4x  ", x);
}

void converter_test() {
    int result;
    
    char* minusOneFourNine = "-149";
    printf("minusOneFourNine: %s\n", minusOneFourNine);
    result = converter(minusOneFourNine);
    printf("minusOneFourNine: %d\n\n", result);
    
    char* minusTen = "-10";
    printf("minusTen: %s\n", minusTen);
    result = converter(minusTen);
    printf("minusTen: %d\n\n", result);
    
    char* allDigits = "1234567890";
    printf("allDigits: %s\n", allDigits);
    result = converter(allDigits);
    printf("allDigits: %d\n\n", result);
    
    char* minusNines = "-999999999999";
    printf("minusNines: %s\n", minusNines);
    result = converter(minusNines);
    printf("minusNines: %d\n\n", result);
    
    char* zero = "0";
    printf("zero: %s\n", zero);
    result = converter(zero);
    printf("zero: %d\n\n", result);

}



void fp_add_test() {
    unsigned bias = 0b01111111;
    bit16 zero = construct(0b0, 0, 0);
    bit16 one = construct(0b0, 0b01111111, 0b0000000);
    bit16 onePointTwoFive = construct(0b0, 0b01111111, 0b0100000);
    bit16 threePointSevenFive = construct(0b0, 0b10000000, 0b1110000);
    bit16 twoTotheSeven = construct(0b0, 0b111 + bias, 0b0000000);
    bit16 twoTotheMinusSeven = construct(0b0, -0b111 + bias, 0b0000000);
    
    
    bit16 minusOnePointTwoFive = construct(0b0, 0b01111111, 0b0100000);
    bit16 minusThreePointSevenFive = construct(0b0, 0b10000000, 0b1110000);
    
    
    print16(SM_ADD(minusOnePointTwoFive, minusThreePointSevenFive));
    
    printf("1.25 + 3.75 = \n");
    print16(fp_add(onePointTwoFive, threePointSevenFive));
    printf("0 + 3.75 = \n");
    print16(fp_add(zero, threePointSevenFive));
    printf("0 + 0 = \n");
    print16(fp_add(zero, zero));
    
    
    printf("2^7 + 1 = \n");
    print16(fp_add(twoTotheSeven, 1));
    printf("2^7 + 2^-7 = \n");
    print16(fp_add(twoTotheSeven, twoTotheMinusSeven));
    
    return;
}