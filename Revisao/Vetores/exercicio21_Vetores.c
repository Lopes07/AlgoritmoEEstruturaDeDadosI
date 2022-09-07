/*21. Faça um programa que receba do usuário dois vetores, A e B, com 10
números inteiros  cada. Crie um novo vetor denominado C calculando C = A - B.
Mostre na tela os dados do vetor C.*/

#include <stdio.h>

int main(){
	int a[10], b[10], c[10];

	for(int i = 0; i < 10; i++){
		printf("Digite o %dº número do vetor A: ", i+1);
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < 10; i++){
		printf("Digite o %dº número do vetor B: ", i+1);
		scanf("%d", &b[i]);		
	}

	for(int i = 0; i < 10; i++){
		c[i] = a[i] - b[i];
		printf("%d\n", c[i]);
	}	
}