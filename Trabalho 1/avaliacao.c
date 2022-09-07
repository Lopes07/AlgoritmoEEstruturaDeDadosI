//Lucas Lopes Silva, Turma M1
#include <stdio.h>
#include <stdlib.h>

void imprimir(double *buffer);

int main(){
    int i;
    float *f;
    double *d;
    char tipo;
    void *buffer = NULL;

    printf("Declare o tipo de dado que deseja armazenar: (i para inteiro, f para float, d para double e s para sair) ");
    scanf("%c", &tipo);
    //fflush(scanf);
    

    switch (tipo)
    {
    case 'i':
        buffer = malloc(sizeof(int));
        printf("Qual inteiro deseja armazenar? ");
        scanf("%i", &i);
        buffer = &i;
        //fflush(scanf);
        break;

    case 'f':
        buffer = malloc(sizeof(float));
        printf("Qual float deseja armazenar? ");
        scanf("%f", &f);
        buffer = &f;
        //fflush(scanf);
        break;

    case 'd':
        buffer = malloc(sizeof(double));
        printf("Qual double deseja armazenar? ");
        scanf("%ld", &d);
        buffer = &d;
        //fflush(scanf);
        break;
    case 's':
        imprimir(buffer);

    default:
        printf("Digite um tipo válido.\n ");
        break;
    }

    do{
        printf("Declare o tipo de dado que deseja armazenar: (i para inteiro, f para float, d para double e s para sair) ");
        scanf("%c", &tipo);
        //fflush(scanf);

        switch (tipo)
        {
        case 'i':
            buffer = realloc(buffer, sizeof(int));
            printf("Qual inteiro deseja armazenar? ");
            scanf("%i", &i);
            buffer = &i;
            //fflush(scanf);
            break;

        case 'f':
            buffer = realloc(buffer, sizeof(float));
            printf("Qual float deseja armazenar? ");
            scanf("%f", &f);
            buffer = &f;
            //fflush(scanf);
            break;

        case 'd':
            buffer = realloc(buffer, sizeof(double));
            printf("Qual double deseja armazenar? ");
            scanf("%ld", &d);
            buffer = &d;
            //fflush(scanf);
            break;
        case 's':
            imprimir(buffer);
            
        default:
            printf("Digite um tipo válido.\n ");
            break;
        }
    }while(tipo != 's');

    return 0;
}

//essa função tem como objetivo imprimir o buffer.
void imprimir(double *buffer){
    //imprimir o buffer completo
    printf("Buffer completo: ");
    for(int n = 0; n < sizeof(buffer); n++){
        printf("%ld\n", *(buffer + n));
    }
    //imprimir primeiro os ints, depois os floats e depois os doubles
    printf("Buffer na ordem: ");
    for(int n = 0; n < sizeof(buffer); n++){
        printf("%i\n%f\n%ld\n", *(buffer + n));
    }
    
}
