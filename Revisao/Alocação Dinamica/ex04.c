/*4. Fac¸a um programa que receba do usuario o tamanho de uma string e chame uma ´
func¸ao para alocar dinamicamente essa string. Em seguida, o usu ˜ ario dever ´ a informar o ´
conteudo dessa string. O programa imprime a string sem suas vogais. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alocaString(int tamanho);
void imprimir();
char *string;

int main(){
    
    int tamanho;

    printf("Declare o tamanho da string: ");
    scanf("%i", &tamanho);

    alocaString(tamanho);

    printf("Declare o conteudo da string: ");
    scanf("%s", string);

    imprimir();
    free(string);
}

/*
 *Essa função tem como objetivo alocar a string de acordo com o que o 
 *usuario pedir
 */
void alocaString(int tamanho){
    string = (char *)malloc(tamanho * sizeof(char) + 1);
}

/*
 *Essa função tem como objetivo imprimir a string digitada pelo
 *usuario sem as vogais
 */
void imprimir(){
    int i;
    printf("Conteudo da string sem as vogais: \n");

    for(i = 0; i < strlen(string); i++){
        if(!(string[i] == 'a' ||string[i] == 'e' ||string[i] == 'i' ||string[i] == 'o' ||string[i] == 'u')){
            printf("%c", string[i]);
        }
    }
}