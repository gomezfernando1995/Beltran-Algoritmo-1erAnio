#include <stdio.h>
#include <stdlib.h>
/*
5. Leer 4 números y mostrar el máximo y el mínimo de ellos
*/
int main()
{
    int numeroIngresado,i,mayor,menor;

    for(i=0;i<4;i++)
    {
        printf("\n Ingrese numero: ");
        scanf("%d",&numeroIngresado);
        if(i==0)
        {
           mayor=numeroIngresado;
           menor=numeroIngresado;
        }else if(numeroIngresado>mayor)
        {
           mayor = numeroIngresado;
        }else if(numeroIngresado<menor)
        {
           menor=numeroIngresado;
        }
    }
    printf("\nEl Mayor numero Ingresado es: %d \n",mayor);
    printf("\nEl Menor numero Ingresado es: %d \n",menor);
    return 0;
}
