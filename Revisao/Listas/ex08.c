#include <stdio.h>
#include <stdlib.h>

//no na lista encadeada
struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data);
void printList(struct Node* head);
int findMaxElement( struct Node* head, int* max, int* pos);

int main(){
    struct Node* head = newNode(1);
    head->next = newNode(5);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(2);
    printf("Lista: ");
    printList(head);

    //encontra o maior elemento
    int max, pos;
    int success =  findMaxElement(head, &max, &pos);
    if (success) {
        printf("Maior elemento: %d\n", max);
        printf("Posicao: %d\n", pos);
    } else {
        printf("Nao foi encontrado o maior elemento.\n");
    }

    return 0;
}

struct Node* newNode(int data) {
    struct Node*  node = (struct Node*) malloc (sizeof (struct Node));

    node->data = data;
    node->next = NULL;

    return node;
}

//funcao para imprimir os elementos da lista
void printList(struct Node* head) {
    struct Node* node = head;

    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int findMaxElement( struct Node* head, int* max, int* pos) {
    if (head == NULL) {
        return 0;
    }

    struct Node* node = head;
    *max =  node->data;
    *pos = 1;

    int count = 1;

    while (node != NULL)
    {
        if(node->data > *max) {
            *max = node->data;
            *pos = count;
        }

        node = node->next;
        count++;
    }

    if (*pos == 0){
        return 0;
    }

    return 1;    
}