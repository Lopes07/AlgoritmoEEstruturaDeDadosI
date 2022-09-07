/*1. Crie um programa que:
(a) Aloque dinamicamente um array de 5 numeros inteiros, ´
(b) Pec¸a para o usuario digitar os 5 n ´ umeros no espac¸o alocado, ´
(c) Mostre na tela os 5 numeros, ´
(d) Libere a memoria alocada*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main(){
    int *vetor;

    vetor = (int *) malloc( TAM * sizeof(int) );

    for (int i = 0; i < TAM; i++){
        printf("\nDeclare o %iº número que deseja armazenar: ", i+1);
        scanf("%i", &vetor[i]);
    }

    for (int i = 0; i < TAM; i++){
        printf("%i\n", vetor[i]);
    }

    free(vetor);
    return 0;
}