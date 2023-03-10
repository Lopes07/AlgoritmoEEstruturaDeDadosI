#include <stdio.h>
#include <stdlib.h>

//no na lista encadeada
struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data);
void printList(struct Node* head);
int removeNElements (struct Node** head, int n) ;

int main(){
    //cria a lista
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Lista original: ");
    printList(head);

    //remover os dois primeiros elementos
    int sucess = removeNElements(&head, 2);
    if (sucess) {
        printf("Lista modificada: ");
        printList(head);
    } else {
        printf("Nao foi possivel remover os elementos.\n");
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

//funcao para remover os n primeiros elementos da lista
int removeNElements (struct Node** head, int n) {
    if(*head == NULL || n <= 0) {
        return 0;
    }

    struct Node* node = *head;
    int count = 1;

    while(count < n && node != NULL){
        node = node->next;
        count++;
    }

    if(node == NULL) {
        return 0;
    }   

    *head = node->next;
    free(node);

    return 1;
}