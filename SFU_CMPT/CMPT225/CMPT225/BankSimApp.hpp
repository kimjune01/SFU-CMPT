//
//  BankSimApp.hpp
//  CMPT225
//
//  Created by June Kim on 2016-06-15.
//  Copyright © 2016 June Kim. All rights reserved.
//

#ifndef BankSimApp_hpp
#define BankSimApp_hpp

#include <stdio.h>
#include "Event.hpp"
#include "EmptyDataCollectionException.hpp"

//Class invariants: FIFO or LILO

// Description: Returns "true" is this queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool isEmpty() ;

// Description: Adds newElement to the "back" of this queue and
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
bool enqueue(const Event& newElement);

// Description: Removes the element at the "front" of this queue and
//              returns "true" if successful, otherwise "false".
// Precondition: This queue is not empty.
// Time Efficiency: O(1)
bool dequeue();

// Description: Retrieves (but does not remove) the element at the
//              "front" of this queue and returns it.
// Precondition: This queue is not empty.
// Postcondition: This queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this queue is empty.
// Time Efficiency: O(1)
Event peek()  throw(EmptyDataCollectionException);

#endif /* BankSimApp_hpp */
