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

void initialize(Queue* q);
void insert(Queue* q, int value);
int remove(Queue* q);
void printQueue(Queue q);
void mergeQueue(Queue *q1, Queue *q2);

int main() {
    Queue q1, q2;
    initialize(&q1);
    initialize(&q2);

    insert(&q1, 1);
    insert(&q1, 2);
    insert(&q1, 3);
    insert(&q2, 4);
    insert(&q2, 5);
    insert(&q2, 6);

    printf("Fila 1: ");
    printQueue(q1);

    printf("Fila 2: ");
    printQueue(q2);

    mergeQueue(&q1, &q2);

    printf("Fila concatenada: ");
    printQueue(q1);

    return 0;
}

void initialize(Queue* q) {
    q->first = NULL;
    q->last = NULL;
    q->size = 0;
}

void insert(Queue* q, int value) {
    Node* newNode = (Node*) malloc (sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->last == NULL) {
        q->first = newNode;
        q->last = newNode;
    } else {
        q->last->next = newNode;
        q->last = newNode;
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
        q->last =  NULL;
    }

    free(temp);
    q->size--;

    return value;
}

void printQueue(Queue q) {
    Node *currentNode = q.first;

    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }

    printf ("\n");    
}

void mergeQueue(Queue *q1, Queue *q2) {
    if (q2->first == NULL) {
        return;
    }

    if (q1->first == NULL) {
        q1->first = q2->first;
    } else {
        q1->last->next = q2->first;
    }

    q1->last = q2->last;
    q1->size += q2->size;

    initialize(q2);
}


