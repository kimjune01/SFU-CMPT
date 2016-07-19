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
#include <stdlib.h>
#include "Queue.h"
#include "LL.h"
#include "LL-node.h"

void inspect(queue_t *q) {
    int empty;
    int size;
    int peeking;

    print(q);
    empty = isEmpty(q);
    if (empty) {
        printf("Queue is empty!\n");
    } else {
        size = qsize(q);
        peeking = peek(q);
        printf("Queue is not empty!\n");
        printf("Its size is %d.\n", size);
        printf("Peeking duck: %d\n\n", peeking);
    }
}

void qtest() {
    queue_t someQueue = freshQueue(7);
    
    inspect(&someQueue);
    
    enqueue(&someQueue, 1);
    enqueue(&someQueue, 2);
    enqueue(&someQueue, 3);
    enqueue(&someQueue, 4);
    enqueue(&someQueue, 5);
    enqueue(&someQueue, 6);
    enqueue(&someQueue, 7);
    
    inspect(&someQueue);
    
    dequeue(&someQueue);
    dequeue(&someQueue);
    dequeue(&someQueue);
    dequeue(&someQueue);

    inspect(&someQueue);
    
    enqueue(&someQueue, 8);
    enqueue(&someQueue, 9);
    enqueue(&someQueue, 10);
    enqueue(&someQueue, 11);

    inspect(&someQueue);
    
    dequeue(&someQueue);
    dequeue(&someQueue);
    dequeue(&someQueue);
    dequeue(&someQueue);
    dequeue(&someQueue);
    dequeue(&someQueue);
    dequeue(&someQueue);
    dequeue(&someQueue);

    inspect(&someQueue);

}

void lltest() {
    //TODO: create 100% test coverage for LL.
    
    printf("Making a new Linked List\n");
    LL_t *linkedList = LLcreate();
    printf("Appending 1, 2, and 3 to the list\n");
    LLappend(linkedList, 1);
    LLappend(linkedList, 2);
    LLappend(linkedList, 3);
    LLprint(linkedList);
    
    printf("Prepending 6, 7, and 8 to the list\n");
    LLprepend(linkedList, 6);
    LLprepend(linkedList, 7);
    LLprepend(linkedList, 8);
    LLprint(linkedList);
    
    printf("Splicing 11, 22, 33, 44 and 55 at various indices to the list\n");
    LLspliceInto(linkedList, 11, 0);
    LLspliceInto(linkedList, 22, 4);
    LLspliceInto(linkedList, 33, 8);
    LLspliceInto(linkedList, 44, 8);
    LLspliceInto(linkedList, 55, 22);
    LLprint(linkedList);
    
    printf("Reversing the list\n");
    LLreverse(linkedList);
    LLprint(linkedList);
    
    printf("Making another new Linked List\n");
    LL_t *otherList = LLcreate();
    printf("Printing the empty list\n");
    LLprint(otherList);
    printf("Reversing the empty list\n");
    LLreverse(otherList);
    LLprint(otherList);
    printf("Prepending 333 to the empty list\n");
    LLprepend(otherList, 333);
    printf("Reversing a list of one node\n");
    LLreverse(otherList);
    LLprint(otherList);
    printf("Prepending 222 to the list\n");
    LLprepend(otherList, 222);
    LLprint(otherList);
    printf("Reversing a list of two nodes\n");
    LLreverse(otherList);
    LLprint(otherList);

    
    
    printf("Appending 111 to the other list\n");
    LLappend(otherList, 111);
    LLprint(otherList);
    
    printf("Merging the list with the other list\n");
    LLmerge(linkedList, otherList);
    LLprint(linkedList);

    LL_t *emptyList = LLcreate();
    printf("Merging the empty list onto the original list\n");
    LLmerge(linkedList, emptyList);
    LLprint(linkedList);
    
    emptyList = LLcreate();
    printf("Merging the original list onto the empty list\n");
    LLmerge(emptyList, linkedList);
    LLprint(emptyList);
    
    return;
    
}

int main(int argc, const char * argv[]) {
    //qtest();
    lltest();
    return 0;
}
