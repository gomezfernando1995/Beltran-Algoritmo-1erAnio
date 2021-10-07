#include <stdio.h>
#include <stdlib.h>
/*  Un obrero necesita calcular su salario semanal, el cual se obtiene de la siguiente manera:
    • Si trabaja 40 horas o menos se le paga $16 por hora
    • Si trabaja más de 40 horas se le paga $16 por cada una de las primeras 40 horas y $20 por cada hora extra.

  Pedir al usuario que ingrese la cantidad de horas trabajadas en la semana, y mostrar por pantalla el salario correspondiente.*/

int main()
{
    int hour,paymentTotal;

    printf("\n Ingrese horas trabajadas por semana: ");
    scanf("%d",&hour);
    while(hour<0 || hour>168)
    {
        printf("\n Error, reingrese horas trabajadas por semana: ");
        scanf("%d",&hour);
    }
    if(hour<=40)
    {
        paymentTotal=hour*16;
    }else {
        paymentTotal=(16*40)+((hour-40)*20);
    }
    printf("\n Su paga total por trabajar %d hs es de %d$ \n",hour,paymentTotal);
    return 0;
}
