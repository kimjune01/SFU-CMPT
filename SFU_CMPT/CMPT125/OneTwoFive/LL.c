
#include <stdio.h>
#include "LL.h"
#include <stdlib.h>

/*
 a pointer to head and tail, both NULL if empty.
 a node contains data and next. 
 All linked lists and node sequences are valid.
*/

LL_t * LLcreate() {
    LL_t *intlist = (LL_t*) malloc(sizeof(LL_t));
    intlist->head = NULL;
    intlist->tail = NULL;
    return intlist;
}

// Adds a new element to the head end of a list
void LLprepend(LL_t * intlist, int value){
    node_t *newNode = (node_t*) malloc(sizeof(node_t));
    newNode->data = value;
    if (intlist->head != NULL) {
        newNode->next = intlist->head;
    } else {
        intlist->tail = newNode;
    }
    intlist->head = newNode;
}

// Adds a new element to the tail of the list
void LLappend(LL_t * intlist, int value){
    node_t *newNode = (node_t*) malloc(sizeof(node_t));
    newNode->data = value;
    if (intlist->tail != NULL) {
        intlist->tail->next = newNode;
    } else {
        intlist->head = newNode;
    }
    intlist->tail = newNode;
}

// Outputs the list elements in sequence from head to tail
void LLprint(LL_t * intlist){
    printf("The list: \n");
    node_t *tempNode = intlist->head;
    while (tempNode != NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
    
}

// Post: inserts node with data x into location i of list L
void LLspliceInto(LL_t *intlist, int value, int index){
    //TODO:
    node_t *newNode = (node_t*) malloc(sizeof(node_t));
    newNode->data = value;

    int indexCounter = 0;
    
    node_t *beforeNode = NULL;
    node_t *afterNode = intlist->head;
    
    while (indexCounter != index) {
        //
        if (afterNode->next == NULL) {
            LLappend(intlist, value);
            return;
        }
        beforeNode = afterNode;
        afterNode = afterNode->next;
        indexCounter ++;
    }
    if (beforeNode == NULL) {
        LLprepend(intlist, value);
        
    } else {
        newNode->next = beforeNode->next;
        beforeNode->next = newNode;
    }
    
    
}

//Post: nodes of list L are now reversed
void LLreverse(LL_t * intlist){
    //TODO: iteratively reverse
    if (intlist->head == NULL || intlist->head->next == NULL) {
        return;
    }
    intlist->tail = intlist->head;
    node_t *wasPrevious = NULL;
    node_t *pivot = intlist->head;
    node_t *wasNext = NULL;
    while (pivot != NULL) {
        wasNext = pivot->next;
        pivot->next = wasPrevious;
        wasPrevious = pivot;
        pivot = wasNext;
    }
    
    intlist->head = wasPrevious;
}

// Pre: L1 and L2 are ordered linked lists
// Post: L1 contains the merged list of L1 and L2, L2 is freed
void LLmerge(LL_t * L1, LL_t * L2){
    if (L2 == NULL || L2->head == NULL) {
        free(L2);
        L2 = NULL;
        return;
    }
    if (L1 == NULL || L1->head == NULL) {
        L1->head = L2->head;
        L1->tail = L2->tail;
        L1 = L2;
        free(L2);
        L2 = NULL;
        return;
    }
    L1->tail->next = L2->head;
    L1->tail = L2->tail;
    free(L2);
    L2 = NULL;
}

