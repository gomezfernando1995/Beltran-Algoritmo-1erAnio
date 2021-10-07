#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>

/*
    3. Realizar un programa que pregunte al usuario el momento del día con una letra (m-mañana, t-tarde, n-noche),
    el sexo con otra letra (m-masculino, f-femenino).Elprograma dirá: buenos días, tardes, o noches
    (según el momento) señor o señora según el sexo.
*/
int main()
{
    char dia,sexo;

    printf("\n m-mañana\n t-tarde\n n-noche\n\n Ingrese momento con letra: ");
    scanf(" %c",&dia);
    __fpurge(stdin);
    dia = tolower(dia);
    while(!(dia=='m' || dia=='t' || dia=='n'))
    {
        printf("\n Error,reingrese momento con letra: ");
        scanf(" %c",&dia);
        __fpurge(stdin);
        dia = tolower(dia);
    }

    printf("\n m-masculino\n f-femenino\n\n Ingrese sexo con letra: ");
    scanf("%c",&sexo);
    __fpurge(stdin);
    sexo=tolower(sexo);
    while(!(sexo=='m' || sexo=='f'))
    {
        printf("\n Error,reingrese sexo con letra: ");
        scanf("%c",&sexo);
        __fpurge(stdin);
        sexo=tolower(sexo);
    }

    if(dia=='m')
    {
        printf("\n Buenos dias ");
    }else if(dia=='t')
    {
        printf("\n Buenas tardes ");
    }else if(dia=='n')
    {
        printf("\n Buenas noches ");
    }

    if(sexo=='m')
    {
        printf("Señor\n");
    }else{
        printf("Señora\n");
    }
    return 0;
}
