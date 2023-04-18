/*Crie um programa que dado uma string, coloque as letras dela em ordem decrescente
usando o algoritmo quick sort.*/

#include <stdio.h>
#include <stdlib.h>

void quickSort(char *str, int left, int right);

int main() {
    char str[100];

    printf("Digite uma string: ");
    scanf("%s", str);

    quickSort(str, 0, strlen(str) - 1);

    printf("String em ordem decrescente: %s\n", str);

    return 0;
}

void quickSort(char *str, int left, int right) {
    int i, j, pivot;
    char temp;

    if(left < right) {
        pivot = left;
        i = left;
        j = right;

        while(i < j) {
            while(str[i] >= str[pivot] && i < right)
                i++;
            while(str[j] < str[pivot])
                j--;
            if(i < j) {
                temp = str[i];
                str[i] = str[j];
                str[j] =  temp;
            }        
        }
        temp = str[pivot];
        str[pivot] = str[j];
        str[j] = temp;

        quickSort(str, left, j - 1);
        quickSort(str, j + 1, right); 
    }
}
