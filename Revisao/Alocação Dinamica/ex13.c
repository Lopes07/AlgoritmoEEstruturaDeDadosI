/*13. Escreva um programa que aloque dinamicamente uma matriz (de inteiros) de dimensoes ˜
definidas pelo usuario e a leia. Em seguida, implemente uma func¸ ´ ao que receba um ˜
valor, retorne 1 caso o valor esteja na matriz ou retorne 0 caso nao esteja na matriz.*/

#include <stdio.h>
#include <stdlib.h>

int verifica(int valor, int **matriz, int nLinhas, int nColunas);

int main(){
    int **matriz, nLinhas, nColunas, valor, retorno, opcao;

    printf("Declare o numero de linhas: ");
    scanf("%i", &nLinhas);
    printf("Declare o numero de colunas: ");
    scanf("%i", &nColunas);

    matriz = (int **) malloc(nLinhas * sizeof(int *));

    for(int i = 0; i < nLinhas; i++){
        matriz[i] = (int *) malloc(nColunas * sizeof(int));

        for(int j = 0; j < nColunas; j++){
            printf("Declare o valor da %i linha e %i coluna: ", i + 1, j + 1);
            scanf("%i", &matriz[i][j]);
        }
    }

    do{
        printf("Declare o valor que deseja verificar: ");
        scanf("%i", &valor);

        retorno = verifica(valor, matriz, nLinhas, nColunas);

        if (retorno == 1){
            printf("Valor encontrado!\n");
        } else {
            printf("Valor nao encontrado.\n");
        }
    } while(opcao == 1);

    free(matriz);

    return 0;
}

int verifica(int valor, int **matriz, int nLinhas, int nColunas){
    for(int i = 0; i <nLinhas; i++){
        for(int j = 0; j < nColunas; j++){
            if (matriz[i][j] == valor){
                return 1;
            } else {
                return 0;
            }
        }
    }
}