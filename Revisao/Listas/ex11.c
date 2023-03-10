#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data);
void printList(struct Node* head);
int countEvenNumbers(struct Node* head);

int main(){
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Lista: ");
    printList(head);

    int count = countEvenNumbers(head);

    printf("Numero de elementos pares: %d\n", count);

    return 0;
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc (sizeof(struct Node));

    node->data = data;
    node->next = NULL;

    return node;
}

void printList(struct Node*  head){
    struct Node* node = head;

    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int countEvenNumbers (struct Node* head){
    if (head == NULL) {
        return 0;
    }

    int count = 0;
    struct Node* node = head;

    while (node != NULL){
        if (node->data % 2 == 0){
            count++;
        }
        node = node->next;
    }

    return count;
}
