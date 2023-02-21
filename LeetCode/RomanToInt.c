#include <stdio.h>

int value ( char opcode );
int RomanToInt( char *s);


int main(void){
    char opcode[100];
    int resultado;
    printf("Qual numero deseja transoformar? ");
    scanf("%s", opcode);

    value(opcode);

    resultado = RomanToInt( opcode );

    printf("%d", resultado);

    return 0;
    
}

int value ( char opcode ){
    switch ( opcode )
    {
    case 'I':
        return 1;
    
    case 'V':
        return 5;
    
    case 'X':
        return 10;
    
    case 'L':
        return 50;
        
    case 'C':
        return 100;
        
    case 'D':
        return 500;

    case 'M':
        return 1000;
    }
    return 0;
}

int RomanToInt( char *s ) {
    int sum = 0;
    for (int i = 0; s[i] != '\0'; i++){
        if ( value( s[i] ) < value( s[i + 1]) ) {
            sum = sum - value( s[i] );
        } else {
            sum += value( s[i] );
        }
    }

    return sum;
}