
/*
 * filename: MyADT.cpp
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

using namespace std;

#include "MyADT.h"
#include <algorithm>
#include <iterator>
#include <cmath>



// Description: returns the number of elements in MyADT
int  MyADT::getElementCount() const{
    int runningSum = 0;
    for (int i; i < NUMBER_OF_CHARACTERS; i++) {
        runningSum = multiElementCount[i];
    }
    //using a single dimensional array with a counter
    return runningSum;
}

// Description: A helper function for getting the character code given a name
// Precondition: newName starts with either a lowercase or an uppercase alphabet character
// Postcondition: Returns 0 for A or a, 1 for B or b, ... 25 for Z or z.
int characterCodeFor(string name) {
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    //the first letter to index the beginning of section for searching
    char newNameFirstLetter = name.at(0);
    //subtracting 'A' codifies the character as ordered integers
    return newNameFirstLetter - 'A';
}

Profile* membersFor(const Profile& newElement, Profile *multiMembers[]) {
    int characterCode = characterCodeFor(newElement.getName());
    
    return multiMembers[characterCode];
}

int* elementCountFor(const Profile& newElement, int multiElementCount[]) {
    int characterCode = characterCodeFor(newElement.getName());
    return &multiElementCount[characterCode];
}

int* currentCapacityFor(const Profile& newElement, int multiCurrentCapacity[]) {
    int characterCode = characterCodeFor(newElement.getName());
    return  &multiCurrentCapacity[characterCode];
}

// Description: Inserts an element.
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
bool MyADT::insert(const Profile& newElement){

    //check if the new element is a unique entry
    if (search(newElement) != NULL){
        //if it is not unique, then do nothing.
        return false;
    }
    
    //find the appropriate array given the character code
    Profile* members = membersFor(newElement, multiMembers);
    int* elementCount = elementCountFor(newElement, multiElementCount);
    int* currentCapacity = currentCapacityFor(newElement, multiCurrentCapacity);

    //if the array is empty, then initiate the array
    if (elementCount == 0) {
        members = new Profile[INITIAL_SIZE];
    }

    //if the array has reached capacity, increase its capacity
    if (elementCount == currentCapacity) {
        int oldCapacity = *currentCapacity;
        *currentCapacity *= 2;
        Profile *temporaryMembers = members;
        members = new Profile[*currentCapacity];
        for (int i = 0; i < oldCapacity; i++) {
            members[i] = temporaryMembers[i];
        }
        delete[] temporaryMembers;
    }
    //append directly to the end of the members array
    members[*elementCount++] = newElement;
    
    
    //insertion success
    return true;
}

// Description: Removes an element.
// Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.
bool MyADT::remove(const Profile& toBeRemoved){
    //check if the candidate exists
    Profile *candidate = search(toBeRemoved);
    //if the candidate is not found, do nothing
    if (candidate == NULL) {
        return false;
    }
    
    //fetch the appropriate array given the character code
    Profile* members = membersFor(toBeRemoved, multiMembers);
    int *elementCount = elementCountFor(toBeRemoved, multiElementCount);
    
    for( int i=0; i< *elementCount; i++ ) {
        if( &members[i] == candidate ){
            //found the candidate. Move the last member in its place.
            members[i] = members[*elementCount-1];
            break;
        }
    }
    (*elementCount)--;
    
    
    /////
    return true;
}

// Description: Searches for target element.
Profile* MyADT::search(const Profile& target){
    //the search result points to nothing by default
    Profile *result = NULL;
    //find the section index by target's character
    
    Profile* members = membersFor(target, multiMembers);
    int elementCount = *elementCountFor(target, multiElementCount);
    
    //for each member in the array in the range
    for (int i = 0; i < elementCount; i++) {
        //look for the place where the target points to the same profile as the array
        if (members[i] == target) {
            //found the target. Assign and exit loop
            result = &members[i];
            break;
        }
    }
    //may be null depending on whether the target was found
    return result;
}

// Description: Removes all elements.
void MyADT::removeAll(){
    
    for (int i =0; i < NUMBER_OF_CHARACTERS; i++) {
        Profile* members = multiMembers[i];
        int* elementCount = &multiElementCount[i];
        //for each element in the array
        for( int i=0; i<*elementCount; i++ ) {
            //remove the members one at a time
            remove(members[i]);
        }
        //indicate empty array
        *elementCount = 0;
    }
    
}

// Description: Prints all elements stored in MyADT.
ostream & operator<<(ostream & os, const MyADT& rhs){
    //append the initial string to the output stream with two newlines
    os << "Here is the list of members:\n\n";
    //for each member in the array
    
    for (int i =0; i < MyADT::NUMBER_OF_CHARACTERS; i++) {
        Profile* members = rhs.multiMembers[i];
        int elementCount = rhs.multiElementCount[i];
        //for each element in the array
        for( int i=0; i<elementCount; i++ ) {
            //remove the members one at a time
            Profile p = members[i];
            //and append its attributes to the output stream without the list of friends
            os << p.getName() << ", " << p.getImage() << ", " << p.getStatus() << ", with " << p.getNumberOfFriends() << " friends" << endl;
        }
    }
    
    return os;
}

