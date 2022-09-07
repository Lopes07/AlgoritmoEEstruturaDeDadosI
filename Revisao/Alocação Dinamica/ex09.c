/*9. Fac¸a um programa que leia uma quantidade qualquer de numeros armazenando-os na ´
memoria e pare a leitura quando o usu ´ ario entrar um n ´ umero negativo. Em seguida, ´
imprima o vetor lido. Use a func¸ao REALLOC*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vetor, i = 0, opcao;

    vetor = (int *)malloc(sizeof(int));

    do{
        printf("Declare o numero que deseja armazenar: ");
        scanf("%i", &vetor[i]);
        
        if(vetor[i] >= 0){
            i++;
            vetor = (int *)realloc(vetor, (i+1) * sizeof(int));
        }
           
    }while(vetor[i] >= 0);

    printf("\n--Numeros digitados--\n");

    for(int j = 0; j <= i; j++){
        printf("%i\n", vetor[j]);
    }

    free(vetor);
    return 0;
}