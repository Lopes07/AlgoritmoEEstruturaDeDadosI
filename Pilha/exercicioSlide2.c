#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[30];
    int idade;
} Pessoa;

typedef struct{
    Pessoa *pessoa;
    int *topo;
    int *base;
    int limite;
}Pilha;

int main(){
    int opcao;
    Pilha *pilha;
    Pessoa *pessoa;

    pilha = (Pilha *)malloc(sizeof(Pilha));
    pessoa = (Pessoa *)malloc(sizeof(Pessoa));

    Reset(pilha);

    do{
        printf("\t0)Insere pessoa \n");
        printf("\t1)Deletar pessoa do topo \n");
        printf("\t2)Deletar pessoa por nome \n");
        printf("\t3)Limpa a pilha \n");
        printf("\t4)Lista na tela as pessoas \n");
        printf("\t5)Sair do programa \n");
        printf("Escolha uma opção: \n");
        scanf("%i", &opcao);
    } while(opcao != 5);


    switch (opcao)
    {
    case 0:
        PUSH(pilha, pessoa);
        break;

    case 1:
        POP(pilha, pessoa);

    case 2:
        break;
    
    case 3: 
        Clear(pilha);

    case 4:
        listar(pilha);
        break;

    case 5:
        free(pilha);
        free(pessoa);
        exit(1);

    
    default:
        printf("Declare um valor válido.\n");
        break;
    }
}

void listar(Pilha *pilha){

        printf("\n###Pessoas###\n");

        while (!(Empty(pilha))){
            Pessoa *pessoa;
            POP(pilha, &pessoa);

            printf("\nNome: %s\tRA: %i\n", pessoa->nome, pessoa->idade);
        }
        
    }

void Reset(Pilha *pilha){
    pilha->topo = NULL;
    pilha->base = NULL;
    pilha->limite = 0;
}

bool Full(Pilha *pilha){
    return false;
}

bool Empty(Pilha *pilha){
    return pilha->topo == 0;
}

bool PUSH(Pilha *pilha, Pessoa *pessoa){
    Pessoa *pessoa;

    pessoa = (Pessoa *)malloc(sizeof(Pessoa));

    if(!pessoa){
        printf("Erro ao alocar memória.\n");
        return;
    }

    memcpy(pessoa, pilha->limite, pilha->pessoa, pilha->limite-1);

    if(pilha->pessoa){
        free(pessoa);
    }
    pilha->pessoa = pessoa;

    pilha->pessoa[pilha->limite - 1] = *pessoa;
    pilha->topo = &pilha->pessoa[pilha->limite -1];
    pilha->base = pilha->pessoa;

    return true;
}

bool POP(Pilha * pilha, Pessoa *pessoa){
    if(Empty(pilha)){
        return;
    }

    pessoa = pilha->topo;

    Pessoa *pessoas;
    pilha->limite--;

    if(pilha->limite == 0){
        free(pilha->pessoa);
        Reset(pilha);   
        return;
    }

    size_t size =sizeof(Pessoa) * pilha->limite;
    pessoas = (Pessoa *)malloc(size);

}