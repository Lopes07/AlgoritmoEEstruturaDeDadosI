#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int isLeapYear(int year);
char* dayOfTheWeek(int day, int month, int year);

int main(){
    char* resposta;
    int dia, mes, ano;

    resposta =  ( char* ) malloc (sizeof(char) *TAM);

    printf("Declare o dia: ");
    scanf("%i", &dia);
    
    printf("Declare o mes: ");
    scanf("%i", &mes);

    printf("Declare o ano: ");
    scanf("%i", &ano);

    resposta = dayOfTheWeek(dia, mes, ano);

    for (int i = 0; i < (strlen(resposta) + 1); i++){
        printf("%c", resposta[i]);
    }

    free(resposta);

    return 0;   
}

int isLeapYear(int year) {
    return ( year % 4 == 0 && year % 100 != 0 ) || ( year % 400 == 0 )  ;
}

char * dayOfTheWeek(int day, int month, int year){
    int totalDays = 4;   //1970_12_31 is Thursday
    int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    for (int i = 1971; i < year; ++i) {
        totalDays += isLeapYear(i) ? 366 : 365;
    }
    for (int i = 1; i < month; ++i) {
        totalDays += monthDays[i] ;
    }
    if (month > 2 && isLeapYear(year)) ++totalDays;
        totalDays += day ;
    
    return days[totalDays % 7] ;
}