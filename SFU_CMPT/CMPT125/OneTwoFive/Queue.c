//
//  Queue.c
//  OneTwoFive
//
//  Created by June Kim on 2016-07-03.
//  Copyright © 2016 June Kim. All rights reserved.
//

#include "Queue.h"
#include <stdlib.h>


queue_t freshQueue(int capacity){
    queue_t newQueue;
    newQueue.data = (int*) malloc(sizeof(int)*capacity);
    newQueue.size = 0;
    newQueue.capacity = capacity;
    newQueue.front = 0;
    newQueue.rear = -1;
    return newQueue;
}

void print(queue_t *q){
    printf("Queue: \n");
    for (int i = 0; i < q->size; i++) {
        //TODO: map i to positions in array
        //printf("q->front: %d\n",q->front);
        //printf("q->rear: %d\n",q->rear);
        int index = i + q->front;
        index = index%(q->capacity);
        //printf("index: %d\n",index);
        
        printf("%d\n",q->data[index]);
    }
    printf("\n");
    return;
}

int isFull(queue_t *q){
    return q->size == q->capacity;
}

void enqueue(queue_t *q, int x){
    if (!isFull(q)) {
        if (q->rear == q->capacity-1) {
            q->rear = -1;
        }
        q->data[++(q->rear)] = x;
        q->size += 1;
    }
    
}

int dequeue(queue_t *q){
    int data = q->data[q->front++];
    if (q->front == q->capacity) {
        q->front = 0;
    }
    q->size--;
    return data;
}

int isEmpty(queue_t *q){
    return q->size <= 0;
}

int qsize(queue_t *q){
    return q->size;
}


int peek(queue_t *q){
    return q->data[q->front];
}