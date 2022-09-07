/*6. Ler nome, sexo e idade. Se sexo for feminino e idade menor que 25, imprime
o nome da pessoa e a palavra “ACEITA”, caso contrario imprimir “NÃO
ACEITA”.*/

#include <stdio.h>
#include <string.h>
#define TAM 50

int main(){
	char nome[TAM], sexo[2];
	int idade;

	printf("Declare seu nome: ");
	scanf("%s", nome);
	
	printf("Sexo: (escreva F para feminino e M para masculino) ");
	scanf("%s", sexo);
	
	printf("Qual a sua idade? ");
	scanf("%d", &idade);

	if(strcmp(sexo, "F") || strcmp(sexo, "f") && idade < 25){
		printf("%s\nACEITA\n", nome);
	}
	else{
		printf("NÃO ACEITA\n");
	}	
}