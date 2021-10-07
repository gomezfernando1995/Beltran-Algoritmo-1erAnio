#include <stdio.h>
#include <stdlib.h>
/*
4. Leer 3 números y mostrar el mayor de ellos.
*/
int main()
{
    int numeroIngresado,i,mayor;

    for(i=0;i<3;i++)
    {
        printf("\n Ingrese numero: ");
        scanf("%d",&numeroIngresado);
        if(i==0)
        {
           mayor=numeroIngresado;
        }else if(numeroIngresado>mayor)
        {
            mayor = numeroIngresado;
        }
    }
    printf("\nEl Mayor numero Ingresado es: %d \n",mayor);
    return 0;
}
