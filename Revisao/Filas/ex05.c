#include <stdio.h>

void calculaMaiorMenorMedia(int lista[], int tamanho, int *maior, int *menor, float *media);

int main(){
    int lista[] = {7, 3, 12, 5, 8};
    int tamanho =  5;
    int maior, menor;
    float media;

    calculaMaiorMenorMedia(lista, tamanho, &maior, &menor, &media);

    printf("Maior: %d.\n", maior);
    printf("Menor: %d.\n", menor);
    printf("Media: %.2f.\n", media);

    return 0;

}

void calculaMaiorMenorMedia(int lista[], int tamanho, int *maior, int *menor, float *media){
    *maior = lista[0];
    *menor = lista[0];
    *media = lista[0];

    for (int i = 0; i< tamanho; i++) {
        if (lista [i] > *maior) {
            *maior =  lista[i];
        }

        if (lista[i] < *menor) {
            *menor = lista[i];
        }

        *media += lista[i];
    }
    *media /= tamanho;    
}