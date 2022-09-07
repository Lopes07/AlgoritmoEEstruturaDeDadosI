/*11. Crie um programa que declare uma estrutura (registro) para o cadastro de alunos.
(a) Deverao ser armazenados, para cada aluno: matr ˜ ´ıcula, sobrenome (apenas um) e
ano de nascimento.
(b) Ao in´ıcio do programa, o usuario dever ´ a informar o n ´ umero de alunos que ser ´ ao˜
armazenados
(c) O programa devera alocar dinamicamente a quantidade necess ´ aria de mem ´ oria ´
para armazenar os registros dos alunos.
(d) O programa devera pedir ao usu ´ ario que entre com as informac¸ ´ oes dos alunos. ˜
(e) Ao final, mostrar os dados armazenados e liberar a memoria alocada. */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int matricula;
    char sobrenome[30];
    int anoNacimento;
}Aluno;

int main(){
    int numeroAlunos;
    Aluno *registro;

    printf("Declare o numero de alunos que serao armzenados: \n");
    scanf("%i", &numeroAlunos);

    registro = (Aluno *) malloc(numeroAlunos * sizeof(Aluno));

    for(int i = 0; i <numeroAlunos; i++){
        printf("Declare a matricula do %i aluno: \n", i + 1);
        scanf("%i", &registro[i].matricula);
        printf("Declare o sobrenome do %i aluno: \n", i + 1);
        scanf("%s", &registro[i].sobrenome);
        printf("Declare o ano de nascimento do %i aluno: \n", i + 1);
        scanf("%i", &registro[i].anoNacimento);
    }

    printf("\n--Alunos registrados--\n");
    for(int i = 0; i <numeroAlunos; i++){
        printf("Matricula: %i\nSobrenome: %s\nAno de Nascimento: %i\n\n", registro[i].matricula, registro[i].sobrenome, registro[i].anoNacimento);       
    }

    free(registro);
    return 0;
}