#include <stdio.h>
#include <stdlib.h>
/*
6. Realizar un programa que pida la base y el exponente y calcule la potencia.
*/
int main()
{
    int i,resultado,exponente,base;
    resultado=1;

    printf("\n Ingrese base: ");
    scanf("%d",&base);
    printf("\n Ingrese exponente: ");
    scanf("%d",&exponente);

    for(i=0;i<exponente;i++)
    {
            resultado=(resultado)*base;
    }

    printf("\n Resultado: %d\n",resultado);

    return 0;
}
