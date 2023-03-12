#include <stdio.h>
#include <Stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    struct Node *first;
    struct Node *last;
}Queue;

void initialize(Queue *Queue);
void insert(Queue *Queue, int value);
int remove(Queue *Queue);
int QueueSize(Queue *Queue);
int hasMoreElements(Queue *f1, Queue *f2);

int main(){
    Queue f1, f2;

    initialize(&f1);
    initialize(&f2);

    insert(&f1, 5);
    insert(&f1, 3);
    insert(&f1, 7);
    
    insert(&f2, 2);
    insert(&f2, 9);

    if (hasMoreElements(&f1, &f2)) {
        printf("A Queue F1 tem mais elementos que a Queue F2.\n");
    } else {
        printf("A Queue F2 tem mais elementos que a Queue F1.\n");
    }

    return 0;


}

void initialize(Queue *Queue){
    Queue->first = NULL;
    Queue->last = NULL;
}

void insert(Queue *Queue, int value){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (Queue->last != NULL) {
        Queue->last->next = newNode;
    } else {
        Queue->first = newNode;
    }
    Queue->last = newNode;
}

int remove(Queue *Queue) {
    if (Queue->first = NULL) {
        return -1;
    }

    int value = Queue->first->value;
    Node *temp = Queue->first;
    Queue->first = Queue->first->next;

    if (Queue->first == NULL) {
        Queue->last == NULL;
    }

    free(temp);

    return value;
}

int QueueSize(Queue *Queue) {
    int size = 0;
    Node *node =  Queue->first;

    while(node != NULL) {
        size++;
        node = node->next;
    }
    return size;
}

int hasMoreElements(Queue *f1, Queue *f2) {
    int size_f1 =  QueueSize(f1);
    int size_f2 = QueueSize(f2);

    return (size_f1 > size_f2);
}
