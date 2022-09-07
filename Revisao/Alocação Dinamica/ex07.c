/*7. Escreva um programa que leia primeiro os 6 numeros gerados pela loteria e depois os 6 ´
numeros do seu bilhete. O programa ent ´ ao compara quantos n ˜ umeros o jogador acertou. ´
Em seguida, ele aloca espac¸o para um vetor de tamanho igual a quantidade de numeros ´
corretos e guarda os numeros corretos nesse vetor. Finalmente, o programa exibe os ´
numeros sorteados e os seus n ´ umeros corretos.*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 6

int main(){
    int *loteria, *bilhete, *corretos, c = 0, i ,j;

    loteria = (int *)malloc(TAM * sizeof(int));
    bilhete = (int *)malloc(TAM * sizeof(int));

    printf("Declare os numeros gerados pela loteria: \n");

    for(int i = 0; i < TAM; i++){
        scanf("%i", &loteria[i]);
    }

    printf("Declare os numeros do seu bilhete: \n");

    for(i = 0; i < TAM; i++){
        scanf("%i", &bilhete[i]);
    }

    for(i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            if(loteria[i] == bilhete[j]){
                c++;
            }
        }
    }

    corretos = (int *)malloc(c * sizeof(int));

    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++){
            if(loteria[i] == bilhete[j]){
                corretos[j] =  bilhete[j];
            }
        }
    }

    printf("\n---Numeros sorteados---\n");
    for(i = 0; i < TAM; i++){
        printf("%i\n", loteria[i]);
    }

    printf("\n---Numeros corretos---\n");
    for(i = 0; i < c; i++){
        printf("%i\n", corretos[i]);
    }
}