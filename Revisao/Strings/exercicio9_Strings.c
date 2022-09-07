/*9. Escreva um programa que substitui as ocorrencias de um caractere ‘0’ em uma
string por outro caractere ‘1’.*/

#include <stdio.h>
#include <string.h>
#define TAM 50

int main(){
	char string[TAM];

	printf("Digite a string: ");
	scanf("%s", string);
		

	for(int i = 0; i < TAM; i++){
		if(strcmp(string, 0)){
			string[i] = 1;
		}
	}
	for(int i = 0; i < TAM; i++){
		printf("%d", string[i]);
	}
}