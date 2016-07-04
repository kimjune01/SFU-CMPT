//
//  Queue.h
//  OneTwoFive
//
//  Created by June Kim on 2016-07-03.
//  Copyright © 2016 June Kim. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} queue_t;

queue_t freshQueue(int capacity);
void print(queue_t *q);
void enqueue(queue_t *q, int x);
int dequeue(queue_t *q);
int isEmpty(queue_t *q);
int qsize(queue_t *q);
int peek(queue_t *q);


#endif /* Queue_h */
