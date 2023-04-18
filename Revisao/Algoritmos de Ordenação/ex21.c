/*21. Considere a seguinte estrutura:
struct pessoa{
int Matricula;
char Nome[30];
float Nota;
};
Faça uma funçao que dado um array de tamanho N dessa estrutura, ordene o array pelo
campo escolhido pelo usuário*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa {
    int Matricula;
    char Nome[30];
    float Nota;
};

int compareMatricula(const void *p1, const void *p2);
int compareNome(const void *p1, const void *p2);
int compareNota(const void *p1, const void *p2);
void ordenar(struct pessoa *pessoas, int n, int campo);

int main() {
    int n, campo;

    printf("Digite o numero de pessoas: ");
    scanf("%d", &n);

    struct pessoa *pessoas = (struct pessoa *) malloc(sizeof(struct pessoa) * n);

    if(pessoas == NULL) {
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }

    printf("Digite as informacoes das pessoas: \n");

    for(int i = 0; i < n; i++) {
        printf("Pessoa %d\n", i + 1);
        
        printf("Matricula: ");
        scanf("%d", &pessoas[i].Matricula);

        printf("Nome: ");
        scanf("%s", pessoas[i].Nome);

        printf("Nota: ");
        scanf("%d", &pessoas[i].Nota);
    }

    printf("Escolha o campo para ordenar: \n");
    printf("\t1. Matricula\n");
    printf("\t2. Nome\n");
    printf("\t3. Nota\n");
    scanf("%d", &campo);

    ordenar(pessoas, n, campo);

    printf("Pessoas ordenadas: \n");

    for(int i = 0; i < n; i++){
        printf("%d -- %s -- %.2f\n", pessoas[i].Matricula, pessoas[i].Nome, pessoas[i].Nota);
    }

    free(pessoas);

    return 0;
}

//funcao para comparar as matriculas de dois alunos
int compareMatricula(const void *p1, const void *p2){
    struct pessoa *pessoa1 = (struct pessoa *) p1;
    struct pessoa *pessoa2 = (struct pessoa *) p2;

    if(pessoa1->Matricula > pessoa2 ->Matricula)
        return - 1;
    else
        return 0;
}

//funcao para comparar os nomes de dois alunos
int compareNome(const void *p1, const void *p2){
    struct pessoa *pessoa1 = (struct pessoa *) p1;
    struct pessoa *pessoa2 = (struct pessoa *) p2;

    return strcmp(pessoa1->Nome, pessoa2->Nome);
}

//funcao para comparas as notas de dois alunos
int compareNota(const void *p1, const void *p2){
    struct pessoa *pessoa1 = (struct pessoa *) p1;
    struct pessoa *pessoa2 = (struct pessoa *) p2;

    if(pessoa1->Nota > pessoa2->Nota)
        return -1;
    else if (pessoa1->Nota < pessoa2->Nota)
        return 1;
    else 
        return 0;
}   

//função para ordenar o array de pessoas pelo campo escolhido pelo usuário
void ordenar(struct pessoa *pessoas, int n, int campo){
    switch(campo) {
        case 1: 
            qsort(pessoas, n, sizeof(struct pessoa), compareMatricula);
            break;
        case 2:
            qsort(pessoas, n, sizeof(struct pessoa), compareNome);
            break;
        case 3:
            qsort(pessoas, n, sizeof(struct pessoa), compareNota);
            break;
        default:
            printf("Campo invalido.\n");
    }
}

