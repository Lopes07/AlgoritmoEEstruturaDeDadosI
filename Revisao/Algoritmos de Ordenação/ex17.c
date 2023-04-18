/*Faça um programa que leia n nomes inserindo-os em uma lista de forma ordenada utilizando a ideia do algoritmo insertion sort. No final, o programa deve mostrar todos os
nomes ordenados alfabeticamente*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMES 100

//Definicao da lista encadeada
typedef struct Node {
    char name[50];
    struct Node* next;
}Node;


void insert(Node** list, char name[]);
void printList(Node* list);

int main() {
    Node* list = NULL;
    char name[50];
    int n;


    printf("Digite a quantidade de nomes que deseja inserir: (no maximo %d)", MAX_NOMES);
    scanf("%i", &n);

    if (n > MAX_NOMES){
        printf("Quantidade invalida.");
        return 1;
    }

    for (int i = 0; i < n; i++){
        printf("Digite o %d nome: ", i + 1);
        scanf("%s", name);
        insert(&list, name);
    }

    printList(list);

    return 0;
}

//Funcao para inserir um no ordenadamente na lista
void insert(Node** list, char name[]) {
    Node* newNode = (Node*) malloc(sizeof (Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if(*list == NULL || strcmp((*list)->name, name) >= 0){
        newNode->next = *list;
        *list = newNode;
    } else {
        Node* curr = *list;
        
        while(curr->next != NULL && strcmp(curr->next->name, name) <0) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

//Funcao para imprimir a lista encadeada
void printList(Node* list) {
    printf("\nNomes ordenados:\n");

    while(list != NULL) {
        printf("%s \n", list->name);
        list = list->next;
    }
}


