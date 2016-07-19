//
//  LL-node.h
//  OneTwoFive
//
//  Created by June Kim on 2016-07-03.
//  Copyright © 2016 June Kim. All rights reserved.
//

#ifndef LL_h
#define LL_h

#include "LL-node.h"

typedef struct {
    node_t * head;
    node_t * tail;
} LL_t;


// Creates and returns a new, empty list
LL_t * LLcreate();

void LLprepend(LL_t * intlist, int value);
// Adds a new element to the tail end of a list
void LLappend(LL_t * intlist, int value);

// Outputs the list elements in sequence from head to tail
void LLprint(LL_t * intlist);

// Post: inserts node with data x into location i of list L
void LLspliceInto(LL_t *intlist, int value, int index);

//Post: nodes of list L are now reversed
void LLreverse(LL_t * intlist);

// Pre: L1 and L2 are ordered linked lists
// Post: L1 contains the merged list of L1 and L2, L2 is freed
void LLmerge(LL_t * L1, LL_t * L2);

#endif /* LL_node_h */
