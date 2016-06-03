//
//  main.c
//  CMPT295
//
//  Created by June Kim on 2016-06-02.
//  Copyright © 2016 June Kim. All rights reserved.
//

#include <stdio.h>
#include "floatlib.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    bit16 one = construct(0b0, 0b01111111, 0b0000000);
    bit16 fourteen = construct(0b0, 0b10000010, 0b1100000); //0011111110100000
    
    
    print16(one);
    print16(fourteen);
    
    bit16 total = fp_add(one, fourteen);
    print16(total);
    return 0;
}
