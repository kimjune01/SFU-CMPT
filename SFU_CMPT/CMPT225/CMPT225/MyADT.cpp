
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
    //using a single dimensional array with a counter
    return elementCount;
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

// Description: Inserts an element.
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
bool MyADT::insert(const Profile& newElement){

    //if array is empty, then initiate the array.
    if (elementCount == 0) {
        members = new Profile[currentCapacity];
    }
    // if the array has reached capacity, increase its capacity
    if (elementCount == currentCapacity) {
        //store the old capacity for copying purposes later
        int oldCapacity = currentCapacity;
        //double the capacity
        currentCapacity *= 2;
        //hold the old members in a temporary array
        Profile *temporaryMembers = members;
        //replace the existing members with the bigger array
        members = new Profile[currentCapacity];
        //copy the contents of the temporary array into the new bigger array
        for (int i=0; i < oldCapacity; i++) {
            members[i] = temporaryMembers[i];
        }
        //release the memory space held by the old array
        delete[] temporaryMembers;
    }
    
    //check if the new element is a unique entry
    if (search(newElement) != NULL){
        //if it is not unique, then do nothing.
        return false;
    }
    
    //get the name of the new member
    string newName = newElement.getName();
    int characterCode = characterCodeFor(newName);
    //fetching the section index for the given name
    int sectionIndex = sectionIndices[characterCode];
    //keep track of where to insert the new member
    

    //increment the size indicator of the array, in preparation for insertion
    elementCount++;
    //insert at section index by iterating from the end of the array
    //it's as if the last place in the array is empty to begin with
    for (int i = getElementCount()-1; i >= sectionIndex; i--) {
        //shift elements to the next place until the section index
        if (i > sectionIndex) {
            //the ith member takes on the value of its left neighbor as i decrements
            members[i] = members[i-1];
        } else if (i == sectionIndex) {
            //reached the insertion index. Inside the for loop to account for sectionIndex==0.
            //insert at the insertion index.
            members[sectionIndex] = newElement;
        }
    }
    
    //update the section indices for all following characters' sections
    for (int i = characterCode; i < NUMBER_OF_CHARACTERS; i++) {
        sectionIndices[i+1]++;
    }
    
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
    
    //for updating the section indices later
    string name = candidate->getName();
    int characterCode = characterCodeFor(name);
    //if the candidate is found, find where the candidate is
    int removalIndex = 0;
    for( int i=0; i<elementCount; i++ ) {
        if( &members[i] == candidate ){
            //found the candidate. Take note of its place.
            removalIndex = i;
            break;
        }
    }
    //shift elements to the left until the second-last place in the array
    for (int i = removalIndex; i<elementCount-1; i++) {
        //take the the right of each member and overwrite
        members[i] = members[i+1];
    }
    //decrement the array's element count to indicate a smaller size
    elementCount--;
    //removal success. Ignore the extra element after the end

    //decrement the section indices for all following sections
    for (int i = characterCode; i < NUMBER_OF_CHARACTERS; i++) {
        sectionIndices[i+1]--;
    }
    return true;
}

// Description: Searches for target element.
Profile* MyADT::search(const Profile& target){
    //the search result points to nothing by default
    Profile *result = NULL;
    //find the section index by target's character
    int characterCode = characterCodeFor(target.getName());
    int sectionIndex = sectionIndices[characterCode];
    //until the beginning of the next section or the end
    int untilIndex = min(sectionIndices[characterCode+1], getElementCount());
    //for each member in the array in the range
    for (int i = sectionIndex; i < untilIndex; i++) {
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
    //for each element in the array
    for( int i=0; i<elementCount; i++ ) {
        //remove the members one at a time
        remove(members[i]);
    }
    //indicate empty array
    elementCount = 0;
    //purge all section indices
    for (int i = 0; i < NUMBER_OF_CHARACTERS; i++) {
        sectionIndices[i] = 0;
    }
}

// Description: Prints all elements stored in MyADT.
ostream & operator<<(ostream & os, const MyADT& rhs){
    //append the initial string to the output stream with two newlines
    os << "Here is the list of members:\n\n";
    //for each member in the array
    for (int i = 0; i < rhs.getElementCount(); i++) {
        //get a reference to each member
        Profile p = rhs.members[i];
        //and append its attributes to the output stream without the list of friends
        os << p.getName() << ", " << p.getImage() << ", " << p.getStatus() << ", with " << p.getNumberOfFriends() << " friends" << endl;
    }
    return os;
}

