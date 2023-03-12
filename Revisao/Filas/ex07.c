#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct queue {
    Node* first;
    Node* last;
    int size;
} Queue;

void initialize (Queue* q);
void insert(Queue* q, int value);
int remove(Queue* q);
int isEmpty(Queue* q);
void deleteNegatives(Queue* q);

int main(){
    Queue q;
    initialize(&q);

    enqueue(&q, -3);
    enqueue(&q, 4);
    enqueue(&q, -1);
    enqueue(&q, 2);
    enqueue(&q, 0);
    enqueue(&q, -5);
    enqueue(&q, 7);

    printf("Fila original: ");
    while (!isEmpty(&q)) {
        printf("%d ", remove(&q));
    }

    deleteNegatives(&q);

    printf("\nFila sem elementos negativos: ");
    while (!isEmpty(&q)) {
        printf("%d ", remove(&q));
    }
    
    return 0;
}

void initialize (Queue* q) {
    q->first = NULL;
    q->last = NULL;
    q->size = 0;
}

void insert(Queue* q, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->last == NULL) {
        q->first = newNode;
        q->last = newNode;
    } else {
        q->last->next =  newNode;
        q->last =  newNode;
    }
    q->size++;
}

int remove(Queue* q) {
    if (q->first == NULL) {
        return -1;
    }

    int value = q->first->data;
    Node* temp = q->first;
    q->first = q->first->next;

    if (q->first == NULL) {
        q->last = NULL;
    }

    free(temp);
    q->size--;

    return value;
}

int isEmpty(Queue* q) {
    return (q->first == NULL);
}

void deleteNegatives(Queue* q) {
    Queue negQueue, posQueue;
    initialize(&negQueue);
    initialize(&posQueue);

    while (!isEmpty(q)) {
        int value = remove(q);
        if(value <0) {
            insert(&negQueue, value);
        } else {
            insert(&posQueue, value);
        }
    }

    while (!isEmpty(&negQueue)){
        remove(&negQueue);
    }

    while (!isEmpty(&posQueue)){
        int value = remove(&posQueue);
        insert(q, value);
    }    
}
