/*5. Fac¸a um programa que leia um numero N e: ´
• Crie dinamicamente e leia um vetor de inteiro de N posic¸oes; ˜
• Leia um numero inteiro X e conte e mostre os m ´ ultiplos desse n ´ umero que existem ´
no vetor*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, *vetor, x, *multiplos, m = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%i", &n);
    printf("Digite o valor X: ");
    scanf("%i", &x);

    vetor = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        printf("Digite o %i numero do vetor: ", i+1);
        scanf("%i", &vetor[i]);
    }

    for(int i = 0; i < n; i++){
        if (vetor[i] %x == 0){
            m++;
        }
    }

    multiplos = (int *)malloc(m * sizeof(int));

    for(int i = 0; i < n; i++){
        if (vetor[i] %x == 0){
            multiplos[i] = vetor[i];
        }
    }

    printf("Existem %i numeros multiplos de %i no vetor\n", m, x);

    for(int i = 0; i < m; i++){
        printf("%i\n", multiplos[i]);
    }

    free(vetor);
    free(multiplos);

    return 0;
}