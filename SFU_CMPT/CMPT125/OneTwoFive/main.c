//
//  main.c
//  OneTwoFive
//
//  Created by June Kim on 2016-05-17.
//  Copyright © 2016 June Kim. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>

int duplicate_students();

int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("mystery: %d", mystery(10));
//    printf("mystery_pyramid: %d", mystery_pyramid(10));
    return 0;
}
//
////counts matching integers in two arrays, inspired by radix sort.
//int duplicate_students(int cmpt125[], int cmpt127[]) {
//    //assume the maximum number of digits is 10.
//    duplicate_students_recursive(10, cmpt125, cmpt127);
//    return 0;
//}
//
//int duplicate_students_recursive(int numberOfSignificantDigits, int leftArray[], int rightArray[]){
//    //no match.
//    if (isEmpty(leftArray) || isEmpty(rightArray)) {
//        return 0;
//    }
//    //the last digit matches, as well as all the previous digits. match.
//    if (numberOfSignificantDigits == 1) {
//        return 1;
//    }
//    
//    int runningSum = 0;
//    
//    int leftBuckets[10][] = {{},{},{},{},{},{},{},{},{},{}};
//    // U U U U U U U U U U
//    int rightBuckets[10][] = {{},{},{},{},{},{},{},{},{},{}};
//    // U U U U U U U U U U
//    
//    //pass the arrays and buckets by reference
//    partition_from_into(leftArray, leftBuckets, numberOfSignificantDigits);
//    partition_from_into(rightArray, rightBuckets, numberOfSignificantDigits);
//    
//    //invariant: leftBuckets and rightBuckets are sorted by their leading digits
//    
//    for (int i = 0; i < lengthOf(leftBuckets); i++) {
//        //pass in a subproblem of size of on average 10 times smaller than the initial problem.
//        runningSum += duplicate_students_recursive(numberOfSignificantDigits-1, leftBuckets[i], rightBuckets[i]);
//        //running time becomes T(n) = T(n/10)*10 + O(n)
//        //T(n) = O(n*log(n))
//    }
//    
//    return runningSum;
//    
//}
//
//void partition_from_into(int partitionee[], int partitions[10][], int sigDig) {
//    for (int i = 0; i < lengthOf(partitionee); i++) {
//        int insignificantDigitMask = power(sigDig, 10);
//        int leadingDigit = partitionee[i] / insignificantDigitMask;
//        assert(leadingDigit < 10);
//        moveFromInto(partitionee[i], partitions[leadingDigit]);
//    }
//}
//
//void moveFromInto(int fromArray[], int intoArray[]) {
//    appendFrominto(remove(fromArray), intoArray);
//}
//
//int power(int base, int exp) {
//    if (exp == 0)
//        return 1;
//    else if (exp % 2)
//        return base * power(base, exp - 1);
//    else {
//        int temp = power(base, exp / 2);
//        return temp * temp;
//    }
//}





