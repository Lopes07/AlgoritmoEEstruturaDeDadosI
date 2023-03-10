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

// Função para imprimir a lista.
void printList(struct Node* head) {
    struct Node* node = head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Função principal de ordenação da lista.
void bubbleSort(struct Node* head) {
    int swapped;
    struct Node* node;
    struct Node* last = NULL;

    // Se a lista estiver vazia ou contiver apenas um elemento, ela já está ordenada.
    if (head == NULL || head->next == NULL) {
        return;
    }

    do {
        swapped = 0;
        node = head;

        // Percorre a lista comparando cada par de elementos adjacentes.
        while (node->next != last) {
            if (node->data > node->next->data) {
                // Troca os elementos adjacentes que estiverem fora de ordem.
                int temp = node->data;
                node->data = node->next->data;
                node->next->data = temp;
                swapped = 1;
            }
            node = node->next;
        }
        // O último elemento já está em sua posição correta, então não precisa ser comparado novamente.
        last = node;
    } while (swapped);
}

// Exemplo de uso.
int main() {
    struct Node* head = newNode(5);
    head->next = newNode(2);
    head->next->next = newNode(8);
    head->next->next->next = newNode(1);
    head->next->next->next->next = newNode(9);

    printf("Lista antes da ordenacao: ");
    printList(head);

    bubbleSort(head);

    printf("Lista apos a ordenacao: ");
    printList(head);

    return 0;
}
