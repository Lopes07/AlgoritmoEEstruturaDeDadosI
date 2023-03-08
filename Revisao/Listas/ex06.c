/*Fac¸a uma func¸ao para concatenar duas listas em uma terceira lista que dever ˜ a ser retor- ´
nada pela func¸ao. N ˜ ao use func¸ ˜ oes j ˜ a implementadas*/

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista encadeada.
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó.
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Função para imprimir os elementos da lista.
void printList(struct Node* head) {
    struct Node* node = head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Função para concatenar duas listas.
struct Node* concatLists(struct Node* head1, struct Node* head2) {
    struct Node* head3 = NULL;
    struct Node* node = NULL;
    
    // Percorre a primeira lista e adiciona os elementos na terceira lista.
    node = head1;
    while (node != NULL) {
        if (head3 == NULL) {
            head3 = newNode(node->data);
            node = node->next;
            continue;
        }
        head3->next = newNode(node->data);
        head3 = head3->next;
        node = node->next;
    }
    
    // Percorre a segunda lista e adiciona os elementos na terceira lista.
    node = head2;
    while (node != NULL) {
        if (head3 == NULL) {
            head3 = newNode(node->data);
            node = node->next;
            continue;
        }
        head3->next = newNode(node->data);
        head3 = head3->next;
        node = node->next;
    }
    
    return head3;
}

// Função principal.
int main() {
    // Cria a primeira lista.
    struct Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    printf("Lista 1: ");
    printList(head1);
    
    // Cria a segunda lista.
    struct Node* head2 = newNode(4);
    head2->next = newNode(5);
    head2->next->next = newNode(6);
    printf("Lista 2: ");
    printList(head2);
    
    // Concatena as duas listas.
    struct Node* head3 = concatLists(head1, head2);
    printf("Lista 3: ");
    printList(head3);
    
    return 0;
}
