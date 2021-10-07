#include <stdio.h>
#include <stdlib.h>
/*
5. Realizar un programa que pida un número y calcule su factorial.
*/
int main()
{
    int resultado,factorial,numeroIngresado;

    printf("Ingrese numero para calcular factorial:");
    scanf("%d",&numeroIngresado);

    resultado =1;
    factorial=numeroIngresado;

    while(factorial>1)
    {
        resultado *=factorial;
        factorial--;
    }
    printf("\n El factorial de %d es %d \n",numeroIngresado,resultado);
    return 0;
}
