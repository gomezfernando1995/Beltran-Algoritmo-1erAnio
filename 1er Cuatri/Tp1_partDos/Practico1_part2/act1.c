#include <stdio.h>
#include <stdlib.h>
/*
1. Realizar un programa que pida al usuario un número y presente los números del 1
    al número que introdujo el usuario.
*/
int main()
{
    int numIngresado,i;

    printf("\n Ingrese un numero positivo: ");
    scanf("%d",&numIngresado);
    while(numIngresado<1)
    {
      printf("\n Reingrese un numero positivo: ");
      scanf("%d",&numIngresado);
    }
    for(i=0;i<=numIngresado;i++)
    {
        printf("\n %d",i);
    }
    return 0;
}
