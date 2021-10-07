#include <stdio.h>
#include <stdlib.h>

/*  Realizá un programa que a partir de un número entero cant ingresado por el usuario permita
    cargar por teclado cant números enteros. La computadora debe mostrar cuál fue el mayor
    número y en qué posición apareció. */

int main()
{
    int cantIngresada,numeroIngresado,anteriorMayor,posicion,i;

    printf("\n Cuantas veces desea ingresar numeros: ");
    scanf("%d",&cantIngresada);
    while(cantIngresada<0)
    {
     printf("\n Reingrese veces desea ingresar numeros: ");
     scanf("%d",&cantIngresada);
    }

    for(i=1; i<cantIngresada+1; i++)
    {
        printf("\n Ingrese numero: ");
        scanf("%d",&numeroIngresado);

        if(i==1 || numeroIngresado>anteriorMayor)
        {
            anteriorMayor=numeroIngresado;
            posicion=i;
        }
    }

    printf("\n El numero mayor es: %d en la posicion: %d",anteriorMayor,posicion);
    return 0;
}
}
