//
//  main.c
//  CMPT295
//
//  Created by June Kim on 2016-06-02.
//  Copyright © 2016 June Kim. All rights reserved.
//

#include <stdio.h>
#include "floatlib.h"
//
//void fp_add_test();
//
//int main(int argc, const char * argv[]) {
//    
//    
//    fp_add_test();
//    
//    return 0;
//}
//
//
//
//void fp_add_test() {
//    unsigned bias = 0b01111111;
//    bit16 zero = construct(0b0, 0, 0);
//    bit16 one = construct(0b0, 0b01111111, 0b0000000);
//    bit16 minusOne = construct(0b1, 0b01111111, 0b0000000);
//    bit16 onePointTwoFive = construct(0b0, 0b01111111, 0b0100000);
//    bit16 threePointSevenFive = construct(0b0, 0b10000000, 0b1110000);
//    bit16 twoTotheSeven = construct(0b0, 0b111 + bias, 0b0000000);
//    bit16 twoTotheMinusSeven = construct(0b0, -0b111 + bias, 0b0000000);
//    
//    bit16 minusOnePointTwoFive = construct(0b1, 0b01111111, 0b0100000);
//    bit16 minusThreePointSevenFive = construct(0b1, 0b10000000, 0b1110000);
//    
//    
//    printf("1.25 + 3.75 = \n");
//    print16(fp_add(onePointTwoFive, threePointSevenFive));
//    printf("0 + 3.75 = \n");
//    print16(fp_add(zero, threePointSevenFive));
//    printf("0 + 0 = \n");
//    print16(fp_add(zero, zero));
//    printf("2^7 + 1 = \n");
//    print16(fp_add(twoTotheSeven, one));
//    printf("2^7 + 2^-7 = \n");
//    print16(fp_add(twoTotheSeven, twoTotheMinusSeven));
//    
//    ////
//    
//    printf("-1.25 + 3.75 = \n");
//    print16(fp_add(minusOnePointTwoFive, threePointSevenFive));
//    printf("-1.25 + -3.75 = \n");
//    print16(fp_add(minusOnePointTwoFive, minusThreePointSevenFive));
//    printf("1.25 + -3.75 = \n");
//    print16(fp_add(onePointTwoFive, minusThreePointSevenFive));
//    printf("2^7 + -1 = \n");
//    print16(fp_add(twoTotheSeven, minusOne));
//    
//
//    
//    return;
//}