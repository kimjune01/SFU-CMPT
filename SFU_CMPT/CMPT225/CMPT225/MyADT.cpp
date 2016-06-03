
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
    //keeping track of the running sum of the number of elements
    int runningSum = 0;
    //for each list
    for (int i = 0; i < NUMBER_OF_CHARACTERS; i++) {
        //add the element count to the running sum
        runningSum += multiElementCount[i];
    }
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

// A private helper function that returns the appropriate list for a given profile's leading character
Profile* membersFor(const Profile& newElement, Profile *multiMembers[]) {
    int characterCode = characterCodeFor(newElement.getName());
    return multiMembers[characterCode];
}

// A private helper function that returns the pointer to the number of elements for a given profile's leading character
int* elementCountFor(const Profile& newElement, int multiElementCount[]) {
    int characterCode = characterCodeFor(newElement.getName());
    return &multiElementCount[characterCode];
}

// A private helper function that returns the pointer to the current capacity for a given profile's leading character
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
        //if it already exists, then do nothing.
        return false;
    }
    
    //find the appropriate array and metadata, given the character code
    //get the address of the appropriate array in this special case to allow assignment
    Profile** members = &(multiMembers[characterCodeFor(newElement.getName())]);
    int* elementCount = elementCountFor(newElement, multiElementCount);
    int* currentCapacity = currentCapacityFor(newElement, multiCurrentCapacity);

    //if the array for the new element's character is empty, then instantiate it
    if (*elementCount == 0) {
        *members = (new Profile[INITIAL_SIZE]);
        *currentCapacity = INITIAL_SIZE;
    }

    //if the array has reached capacity, increase its capacity
    if (*elementCount == *currentCapacity) {
        int oldCapacity = *currentCapacity;
        //double the capacity
        *currentCapacity *= 2;
        //hold the members for the time being
        Profile *temporaryMembers = *members;
        //instantiate the new bigger array
        *members = new Profile[*currentCapacity];
        //copy the contents of the old array into the new array
        for (int i = 0; i < oldCapacity; i++) {
            //the parantheses aroune *members ensures access of each member, not a dereference of the ith list
            (*members)[i] = temporaryMembers[i];
        }
        //prevent memory leaks
        delete[] temporaryMembers;
    }
    
    //append directly to the end of the members array
    //the parantheses around *members keeps the references to the last member of the inner array, and not the outer array
    //see c++ operator precedence for more detail
    (*members)[(*elementCount)] = newElement;
    //increment the element counter for the array. Using pointers makes this convenient
    (*elementCount)++;
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
    
    //fetch the appropriate array and its length
    Profile* members = membersFor(toBeRemoved, multiMembers);
    int *elementCount = elementCountFor(toBeRemoved, multiElementCount);
    
    //look through the section
    for( int i=0; i< *elementCount; i++ ) {
        if( &members[i] == candidate ){
            //found the candidate. Move the last member in its place.
            members[i] = members[*elementCount-1];
            break;
        }
    }
    //decrement the element count to indicate a now smaller array size
    (*elementCount)--;
    
    //successful removal
    return true;
}

// Description: Searches for target element.
Profile* MyADT::search(const Profile& target){
    //the search result points to nothing by default
    Profile *result = NULL;
    
    //fetch the appropriate array and its length
    Profile* members = membersFor(target, multiMembers);
    int elementCount = *elementCountFor(target, multiElementCount);
    
    //for each member in the array
    for (int i = 0; i < elementCount; i++) {
        //look for the place where the target points to the same profile as the array
        if (members[i] == target) { //see overload operator in Profile
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
    
    //for each letter in the alphabet
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

    //for each character of the alphabet
    for (int i =0; i < MyADT::NUMBER_OF_CHARACTERS; i++) {
        //fetch the appropriate array and its length
        Profile* members = rhs.multiMembers[i];
        int elementCount = rhs.multiElementCount[i];
        //for each member in the inner array
        for( int i=0; i<elementCount; i++ ) {
            //get a reference to each member
            Profile p = members[i];
            //and append its attributes to the output stream without the list of friends
            os << p.getName() << ", " << p.getImage() << ", " << p.getStatus() << ", with " << p.getNumberOfFriends() << " friends" << endl;
        }
    }
    return os;
}

