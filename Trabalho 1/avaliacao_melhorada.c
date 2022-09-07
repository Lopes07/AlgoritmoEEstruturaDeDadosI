//Lucas Lopes Silva, Turma M1
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int inteiro;
    float floatF;
    double doubleD;
} Valor;

void *adicionaInt( int *ponteiroInt, int tamanhoListaInt);
void *adicionaFloat( float *ponteiroFloat, int tamanhoListaFloat );
void *adicionaDouble( double *ponteiroDouble, int tamanhoListaDouble );
void imprimir(Valor *ponteiroValor, int tamanhoLista, int *ponteiroInt, int tamanhoListaInt, int *ponteiroFloat, int tamanhoListaFloat, 
             int *ponteiroDouble, int tamanhoListaDouble);

int main(){

    int *ponteiroInt;
    float *ponteiroFloat;
    double *ponteiroDouble;

    int tamanhoLista = 0, tamanhoListaInt = 0, tamanhoListaFloat = 0, tamanhoListaDouble = 0;
    Valor *ponteiroValor = NULL;

    int tipo = 0;


    do {
        printf("\nDeclare o tipo de dado que deseja armazenar: \n");
        printf("\t1) Adicionar inteiro: \n");
        printf("\t2) Adicionar float: \n");
        printf("\t3) Adicionar double: \n");
        printf("\t4) Sair \n");
        scanf("%i", &tipo);
        getchar();

        switch ( tipo )
        {
        case 1:
            ponteiroInt = adicionaInt( ponteiroInt, tamanhoListaInt );
            ponteiroValor = &ponteiroInt;
            tamanhoListaInt++;
            tamanhoLista++;
            break;

        case 2:
            ponteiroFloat = adicionaFloat( ponteiroFloat, tamanhoListaFloat );
            ponteiroValor = &ponteiroFloat;
            tamanhoListaFloat++;
            tamanhoLista++;
            break;

        case 3:
            ponteiroDouble = adicionaDouble( ponteiroDouble, tamanhoListaDouble );
            ponteiroValor = &ponteiroDouble;
            tamanhoListaDouble++;
            tamanhoLista++;
            break;

        case 4:
            imprimir( ponteiroValor, tamanhoLista, ponteiroInt,tamanhoListaInt, ponteiroFloat, tamanhoListaFloat, 
             ponteiroDouble, tamanhoListaDouble );
            free( ponteiroValor );
            free( ponteiroInt );
            free( ponteiroFloat );
            free( ponteiroDouble );
            exit( 1 );
            break;
            
        default:
            printf("Digite um tipo válido.\n ");
            break;
        }
    } while((tipo >= 1) || (tipo <= 4));

    return 0;
}

/*
 *Essa função tem como objetivo receber um inteiro do usuário e armazená-la 
 *na região específica da struct reservada aos inteiros.    
 */
void *adicionaInt( int *ponteiroInt, int tamanhoListaInt){
    if ( tamanhoListaInt != 0 ){ //nao é o primeiro valor
        ponteiroInt = realloc(ponteiroInt, sizeof(int) * (tamanhoListaInt + 1));
    } else { //é o primeiro valor
        ponteiroInt = malloc(sizeof(int));
    }

    printf("\nDigite o inteiro que deseja armazenar: ");
    scanf("%i", &ponteiroInt);
    getchar();

    return ponteiroInt;
}

/*
 *Essa função tem como objetivo receber um float do usuário e armazená-la 
 *na região específica da struct reservada aos floats.    
 */
void *adicionaFloat( float *ponteiroFloat, int tamanhoListaFloat){
    if ( tamanhoListaFloat != 0 ){ //nao é o primeiro valor
        ponteiroFloat = realloc(ponteiroFloat, sizeof(float) * (tamanhoListaFloat + 1));
    } else { //é o primeiro valor
        ponteiroFloat = malloc(sizeof(float));
    }

    printf("\nDigite o float que deseja armazenar: ");
    scanf("%f", &ponteiroFloat);
    getchar();

    return ponteiroFloat;
}

/*
 *Essa função tem como objetivo receber um double do usuário e armazená-la 
 *na região específica da struct reservada aos doubles.    
 */
void *adicionaDouble( double *ponteiroDouble, int tamanhoListaDouble){
    if ( tamanhoListaDouble != 0 ){ //nao é o primeiro valor
        ponteiroDouble = realloc(ponteiroDouble, sizeof(double) * (tamanhoListaDouble + 1));
    } else { //é o primeiro valor
        ponteiroDouble = malloc(sizeof(double));
    }

    printf("\nDigite o double que deseja armazenar: ");
    scanf("%lf", &ponteiroDouble);
    getchar();

    return ponteiroDouble;
}

/*
 *Essa função tem como objetivo imprimir todo o buffer e depois somente os ints, depois somente os floats e depois somente os doubles.
 */
void imprimir(Valor *ponteiroValor, int tamanhoLista, int *ponteiroInt, int tamanhoListaInt, int *ponteiroFloat, int tamanhoListaFloat, 
             int *ponteiroDouble, int tamanhoListaDouble){
    if ( tamanhoLista > 0 ){
        for( int i = 0; i < tamanhoLista; i++ ){
            printf("%i\n", ( ponteiroValor + i ) -> inteiro );
            printf("%.2f\n", ( ponteiroValor + i ) -> floatF );
            printf("%lf\n", ( ponteiroValor + i) -> doubleD );
        }
    } else {
        printf("\nNão foi inserido nenhum número.\n");
    }

    if ( tamanhoListaInt > 0 ){
        for( int i = 0; i < tamanhoListaInt; i++){
            printf("%i\n", ponteiroInt + i);
        }
    } else {
        printf("\nNão foi inserido nenhum inteiro.\n");
    }

    if ( tamanhoListaFloat > 0 ){
        for( int i = 0; i < tamanhoListaFloat; i++){
            printf("%f\n", ponteiroFloat + i);
        }
    } else {
        printf("\nNão foi inserido nenhum float.\n");
    }

    if ( tamanhoListaDouble > 0 ){
        for( int i = 0; i < tamanhoListaDouble; i++){
            printf("%lf\n", ponteiroDouble + i);
        }
    } else {
        printf("\nNão foi inserido nenhum double.\n");
    }
    
}