#include <stdio.h>
#include <stdlib.h>
#define TAM 100

char* reverseString( char* s);

int main() {
    char* string;
    char* stringInvertida;
    
    string = (char* ) malloc (sizeof(char) * TAM);
    stringInvertida = (char* ) malloc (sizeof(char) * TAM);

    printf("Declare a string que deseja inverter: ");
    scanf("%s", string);

    stringInvertida = reverseString( string );
    
    for (int i = 0; i < (sizeof(stringInvertida) + 1); i++){
        printf("%c", stringInvertida[i]);
    }

    free(string);
    free(stringInvertida);

    return 0;
}

char* reverseString(char* s) {
    char ch;
    int i, j;
    for ( i = 0, j = strlen(s)-1; i < j; i++, j--) {
        ch = s[i];
        s[i] = s[j];
        s[j] = ch;
    }
    return s;
}