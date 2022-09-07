/*Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de cada variavel usando os ponteiros. Imprima os valores das variáveis antes e após a 
modificac¸ao.*/
#include <stdio.h>

int main(){
	int i = 10, *pi;
	float f = 5.5, *pf;
	char c = 'r', *pc;

	pi = &i;
	pf = &f;
	pc = &c;

	printf("Valores antes da modificacao: %d\n%0.1f\n%c\n", *pi, *pf, *pc);

	*pi = 3;
	*pf = 5.7;
	*pc = 'l';

	printf("Valores depois da modificacao: %d\n%0.1f\n%c\n", *pi, *pf, *pc);
}