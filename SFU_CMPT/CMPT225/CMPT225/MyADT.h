
/*
 * filename: MyADT.h
 *
 * Class Description: A data collection ADT class to satisfy Assn 1's requiremetns.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicate).
 *                   - Once it has been ascertained that the element has not already been
 *                     inserted, its data structure allows insertion in O(1)
 *                   - Once the element to be removed as been found,
 *                     its data structure allows removal in O(1).
 *                   - Its data structure is resizable: when full, it expands to accommodate
 *                     new element insertions. This is done unbeknown to the client code.
 *
 * Creation date: June 1, 2016
 * Author: June Kim
 */

#ifndef __CMPT225__MyADT__
#define __CMPT225__MyADT__

#include <iostream>
#include <stdio.h>
#include "Profile.h"

using namespace std;

class MyADT {
    
private:
    static const int NUMBER_OF_CHARACTERS = 26;     //initial size of array
    
    Profile *multiMembers[NUMBER_OF_CHARACTERS];    //2d array of members
    int multiElementCount[NUMBER_OF_CHARACTERS];
    int multiCurrentCapacity[NUMBER_OF_CHARACTERS];
    ////////
    
    //    Profile *members;                       //array of profiles as members
    static const int INITIAL_SIZE = 32;     //initial size of array
//    int currentCapacity = INITIAL_SIZE;     //current capacity of array
//    int elementCount = 0;                   //current number of profiles in MyADT
    //indices for the letters of the alphabet in the array
    //a is 0, b is 1, .. z is 25
    //int sectionIndices[NUMBER_OF_CHARACTERS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
public:
    

    
    // Description: Returns the total of elements currently stored in MyADT.
    int  getElementCount() const;
    
    // Description: Inserts an element.
    // Precondition: newElement must not already be in data collection.
    // Postcondition: newElement inserted and the appropriate elementCount has been incremented.
    bool insert(const Profile& newElement);
    
    // Description: Removes an element.
    // Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.
    bool remove(const Profile& toBeRemoved);
    
    // Description: Searches for target element.
    Profile* search(const Profile& target);
    
    // Description: Removes all elements.
    void removeAll();
    
    // Description: Prints all elements stored in MyADT.
    friend ostream & operator<<(ostream & os, const MyADT& rhs);
    
};




#endif /* defined(__CMPT225__MyADT__) */
