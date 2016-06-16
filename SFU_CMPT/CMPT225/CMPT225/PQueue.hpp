//
//  PQueue.hpp
//  CMPT225
//
//  Created by June Kim on 2016-06-15.
//  Copyright © 2016 June Kim. All rights reserved.
//

#ifndef PQueue_hpp
#define PQueue_hpp

#include <stdio.h>
#include "Event.hpp"
#include "EmptyDataCollectionException.hpp"

//Class Invariant: The elements stored in this Priority Queue are always sorted.

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool isEmpty() ;

// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
bool enqueue(const Event& newElement);

// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
bool dequeue();

// Description: Retrieves (but does not remove) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
Event peek()  throw(EmptyDataCollectionException);

#endif /* PQueue_hpp */
