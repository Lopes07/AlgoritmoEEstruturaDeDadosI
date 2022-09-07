/*8. Crie um programa que contenha um array de float contendo 10 elementos. Imprima o
enderec¸o de cada posic¸ao desse array.*/
#include <stdio.h>

int main(){
	float array[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0}, *pArray;

	for(int i = 0; i < 10; i++){
		printf("Endereco da %i posicao: %p\n", i+1, pArray);
	}
	
}