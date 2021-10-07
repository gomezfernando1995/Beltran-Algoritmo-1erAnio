#include <stdio.h>
#include <stdlib.h>
/*
8. Cree un programa que pida tres números e indique si el tercero es igual a la suma del primero y el segundo.
*/
int main()
{
    int numeroIngresado,i,suma;
    suma =0;

    for(i=0;i<3;i++)
    {
        printf("\n Ingrese numero: ");
        scanf("%d",&numeroIngresado);
        if(i<2)
        {
          suma+=numeroIngresado;
        }
    }
    if(suma==numeroIngresado)
    {
        printf("\n La suma es: %d y el ultimo N°Ingresado es %d\n ",suma,numeroIngresado);
    }
    return 0;
}
