#include <stdio.h>
#include <stdlib.h>

/*
1. Asignar valores a 2 variables desde código y mostrar el contenido de la mayor por pantalla
*/

int main()
{
    int valorUno,valorDos;
    valorUno= 20;
    valorDos=50;

    if(valorUno>valorDos)
    {
       printf("Valor Uno es mayor : %d \n",valorUno);
    }else
    {
        printf("Valor Dos es mayor : %d \n",valorDos);
    }
    return 0;
}
