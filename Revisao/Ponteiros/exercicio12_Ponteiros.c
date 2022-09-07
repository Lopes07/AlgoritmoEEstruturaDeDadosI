/*Fac¸a um programa que leia tres valores inteiros e chame uma func¸ ˆ ao que receba estes 3 ˜
valores de entrada e retorne eles ordenados, ou seja, o menor valor na primeira variavel, ´
o segundo menor valor na variavel do meio, e o maior valor na ´ ultima vari ´ avel. A func¸ ´ ao˜
deve retornar o valor 1 se os tres valores forem iguais e 0 se existirem valores diferentes. ˆ
Exibir os valores ordenados na tela.
*/

#include <stdio.h>
#include <stdlib.h>
int ordena(int *x, int *y, int *z);

int main(){
	int x, y, z, *px, *py, *pz;

	px = &x;
	py = &y;
	pz = &z;

	printf("Declare o valor de X: ");
	scanf("%i", &x);
	printf("Declare o valor de Y: ");
	scanf("%i", &y);
	printf("Declare o valor de Z: ");
	scanf("%i", &z);

	ordena(&x, &y, &z);

	printf("%i\n%i\n%i\n", x, y, z);
}

int ordena(int *x, int *y, int *z){
	int aux, aux2;
	if((*x < *y && *x < *z) && (*y > *x && *y < *z) &&(*z > *x && *z > *y)){
		*x = *x;
		*y = *y;
		*z = *z;	
	}
	
	if((*x < *y && *x < *z) && (*z < *y && *z > *x) && (*y > *z && *y > *x)){
		*x = *x;
		aux = *y;
		*y = *z;
		*z = aux;
	}
	
	if((*y < *x && *y < *z) && (*x < *z && *x > *y) && (*z > *y && *z > *x)){
		aux = *x;
		*x = *y;
		*y = aux;
		*z = *z;
	}
	
	if((*y < *x && *y < *z) && (*z > *y && *z < *x) && (*x > *y && *x > *z)){
		aux = *z;
		*z = *y;
		*y = *x;
		*x = aux;
	}
	
	if((*z < *x && *z < *y) && (*x > *z && *x < *y) && (*y > *x && *y > *z)){
		aux = *z;
		*z = *x;
		*x = *y;
		*y = aux;	
	}
	
	if((*z < *x && *z < *y) && (*y < *x && *y > *z) && (*x > *y && *x > *z)){
		aux = *x;
		*x = *z;
		*y = *y;
		*z = aux;
	}

	if(*x == *y == *z){
		return 1;
	}
	else{
		return 0;
	}
}