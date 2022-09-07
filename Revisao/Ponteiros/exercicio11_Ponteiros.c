/*11. Crie um programa que contenha um array contendo 5 elementos inteiros. Leia esse array
do teclado e imprima o enderec¸o das posic¸oes contendo valores pares.*/

#include <stdio.h>

int main(){
	int array[5], *pArray;
	pArray = array;

	for(int i = 0; i < 5; i++){
		printf("Declare o %i elemento do array: ", i+1);
		scanf("%i", &array[i]);
	}
	
	for(int i = 0; i < 5; i++){
		if(array[i] %2 == 0){
			
			printf("Endereco: %p\n", pArray);
		}
		pArray++;
	}
}