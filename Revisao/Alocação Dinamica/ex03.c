/*3. Fac¸a um programa que leia do usuario o tamanho de um vetor a ser lido e fac¸a a alocac¸ ´ ao˜
dinamica de mem ˆ oria. Em seguida, leia do usu ´ ario seus valores e mostre quantos dos ´
numeros s ´ ao pares e quantos s ˜ ao˜ ´ımpares.*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vetor, tamanho, par = 0, impar = 0;
    
    printf("Declare o tamanho do vetor a ser alocado: ");
    scanf("%i", &tamanho);

    vetor = (int *)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++){
        printf("\nDigite o %i numero a ser armazenado: ", i+1);
        scanf("%i", &vetor[i]);

        if (vetor[i] %2 == 0){
            par++;
        } else {
            impar++;
        }
    }

    for (int i = 0; i < tamanho; i++){
        printf("%i\n", vetor[i]);
    }

    printf("\n\n%i numeros pares.\n", par);
    printf("\n\n%i numeros impares.\n", impar);

    free(vetor);
    return 0;

}