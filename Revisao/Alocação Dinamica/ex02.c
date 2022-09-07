/*2. Fac¸a um programa que leia do usuario o tamanho de um vetor a ser lido e fac¸a a alocac¸ ´ ao˜
dinamica de mem ˆ oria. Em seguida, leia do usu ´ ario seus valores e imprima o vetor lido*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vetor, tamanho;
    
    printf("Declare o tamanho do vetor a ser alocado: ");
    scanf("%i", &tamanho);

    vetor = (int *)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++){
        printf("\nDigite o %i numero a ser armazenado: ", i+1);
        scanf("%i", &vetor[i]);
    }

    for (int i = 0; i < tamanho; i++){
        printf("%i\n", vetor[i]);
    }

    free(vetor);
    return 0;

}