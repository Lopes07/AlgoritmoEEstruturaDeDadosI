#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* newNode (int data);
void printList(struct Node* head);
int swapElements(struct Node* head, int index1, int index2);

int main(){
     struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Lista original: ");
    printList(head);

    //troca os elementos de posicao
    int success =  swapElements(head, 2, 4);

    if (success) {
        printf("Lista modificada: ");
        printList(head);
    } else {
        printf("Operacao invalida.\n");
    }

    return 0;
}

struct Node* newNode (int data){
    struct Node* node = (struct Node* ) malloc (sizeof (struct Node));
     
    node->data = data;
    node->next = NULL;

    return node;
}

void printList (struct Node* head) {
    struct Node* node = head;

    while (node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int swapElements(struct Node* head, int index1, int index2) {
    if (head == NULL || index1 <= 0 || index2 <= 0) {
        return 0;
    }

    struct Node* node1 = head;
    struct Node* node2 = head;
    int count = 1;

    //percorre a lista ate encontrar os nos correspondentes aos indicies
    while (node1 != NULL && count < index1)
    {
        node1 = node1->next;
        count++;
    }
    while (node2 != NULL && count < index2)
    {
        node2 = node2->next;
        count++;
    }

    //verifica se os nos foram encontrados e sao diferentes
    if (node1 == NULL || node2 == NULL || node1 == node2) {
        return 0;
    }

    //troca os valores dos nos
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;

    return 1;
}
