/*18. Crie um programa que dado uma string, coloque as letras dela em ordem crescente pelo
algoritmo bubble sort.
*/

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(char str[]);

int main() {
    char str[100];

    printf("Digite uma string: ");
    scanf("%s", str);

    bubbleSort(str);

    printf("String ordenada em ordem crescente: %s\n", str);

    return 0;
}



//Funcao bubble sort para ordenar as letras em ordem crescente 
void bubbleSort(char str[]) {
    int i, j, n;
    char aux;

    n = strlen(str);

    for(i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if(str[j] > str[j + 1]) {
                aux = str[j];
                str[j] = str[j + 1];
                str[j + 1] = aux;                
            }
        }
    }
}