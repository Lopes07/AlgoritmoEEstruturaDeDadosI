#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

struct queueNode {
    int data;
};

typedef struct {
  struct queueNode *arr[101];
  int first;
  int last;  
} MyStack;


MyStack* myStackCreate() {
    MyStack *q = (MyStack*) malloc (sizeof(MyStack));
    q->first = -1;
    q->last = -1;
    return q;
}

void insert(MyStack *q, struct queueNode* value) {
    q->arr[++q->last] = value;
    if (q->first == -1) {
        q->first = 0;
    } 
}

struct queueNode* dequeue(MyStack* q) {
    struct queueNode*  value = q->arr[q->first];

    if (q->first == q->last) {
        q->first = q->last = -1;
    } else {
        q->first++;
    }
    
    return value;
}

void myStackPush(MyStack* q, int x) {
    struct queueNode* node = (struct queueNode*) malloc (sizeof(struct queueNode));
    int size;

    node->data = x;
    insert(q, node);
    size = q->last - q->first +1;

    while (size > 1) {
        struct queueNode* first = dequeue(q);
        insert(q, first);
        size--;
    }
}

int myStackPop(MyStack* q) {
  struct queueNode* first = dequeue(q);
  int value = first->data;
  free(first);
  return value;
}

int myStackTop(MyStack* q) {
  struct queueNode* first = q->arr[q->first];
  return first->data;
}

bool myStackEmpty(MyStack* q) {
  return q->first == -1;
}

void myStackFree(MyStack* q) {
    while (!myStackEmpty(q)) {
        struct queueNode* first = dequeue(q);
        free(first);
    }
    free(q);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/