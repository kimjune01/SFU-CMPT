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

int main(int argc, const char * argv[]) {
    qtest();
    
    return 0;
}
