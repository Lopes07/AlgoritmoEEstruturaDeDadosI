/*Faça um programa que leia n nomes e ordene-os pelo tamanho utilizando o algoritmo
selection sort*/

#include <stdio.h>
#include <stdlib.h>

void selectionSort(char names[][100], int n);


int main() {
    int n, i;
    char names[100][100];

    printf("Digite a quantidade de nomes que deseja inserir: ");
    scanf("%d", &n);

    printf("Digite os nomes a serem ordenados: \n");

    for(i = 0; i < n; i++){
        scanf("%s", names[i]);
    }

    selectionSort(names, n);

    printf("Nomes ordenados por tamanho: \n");

    for(i = 0; i < n; i++){
        printf("%s\n", names[i]);
    }

    return 0;
}

void selectionSort(char names[][100], int n) {
    int i, j, min_idx;
    char temp[100];

    for(i = 0; i < n - 1; i++){
        min_idx = i;
        for(j = i + 1; j < n; j++){
            if(strlen(names[j])< strlen(names[min_idx])){
                min_idx = j;
            }
        }

        if(min_idx != i) {
            strcpy(temp, names[i]);
            strcpy(names[i], names[min_idx]);
            strcpy(names[min_idx], temp);
        }
    }
}