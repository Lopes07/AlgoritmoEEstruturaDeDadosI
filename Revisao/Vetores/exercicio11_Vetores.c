/*11. Faça um programa que preencha um vetor com 10 números reais, calcule e mostre a 
quantidade de numeros negativos e a soma dos números positivos desse vetor. */

#include <stdio.h>

int main(){
	float vetor[10];
	int neg, soma = 0;

	for(int i =0; i<10; i++){
		printf("Digite o %dº número do vetor: ", i+1);
		scanf("%f", &vetor[i]);

		if(vetor[i] >= 0){
			soma = soma + vetor[i];
		}
		else{
			neg++;
		}
	}

	printf("Quantidade de números negativos: %d\nSoma dos números positivos: %d\n", neg, soma);	
}