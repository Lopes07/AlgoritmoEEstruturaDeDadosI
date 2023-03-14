#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct {
    int arr[100];
    int head;
    int tail;
    int size;    
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*) malloc (sizeof(MyQueue));
    q->head = 0;
    q->tail = 0;
    q->size = 0;

    return q;
}

void myQueuePush(MyQueue* q, int x) {
    if (q == NULL) {
      return;
    }

    q->size++;
    q->arr[q->tail] = x;
    q->tail = (q->tail + 1)%100;
}

int myQueuePop(MyQueue* q) {
    if (q == NULL) {
      return NULL;
    }

    q->size--;
    q->head = (q->head + 1)%100;
    return (q->arr[(q->head - 1)%100]);
}

int myQueuePeek(MyQueue* q) {
    if (q == NULL) {
      return NULL;
    }
    return q->arr[q->head];
}

bool myQueueEmpty(MyQueue* q) {
    if (q == NULL) {
      return false;
    }

    return (q->size?false:true);
}

void myQueueFree(MyQueue* q) {
    if (q == NULL) {
      return;
    }

    free(q);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/