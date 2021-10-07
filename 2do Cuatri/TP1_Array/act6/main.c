#include <stdio.h>
#include <stdlib.h>
/*
 Crear un arreglo que permita almacenar un máximo de 20 números. Para ello, deberá solicitar la carga por el usuario
 hasta que el mismo ha ingreso el valor -1. Luego, recorra el vector informando los valores que se han llegado a
 almacenar el mismo.
*/

int main()
{
    int numero[20];
    int i;

    for(i=0;i<20;i++)
    {
        numero[i]=-2;
    }

    for(i=0;i<20;i++)
    {
        printf("\n Numero ? ");
        scanf("%d",&numero[i]);
        if(numero[i]==-1)
        {
            break;
        }
    }
    for(i=0;i<20;i++)
    {
        if(numero[i]!=-2)
        {
        printf("\n%d)%d\n",i,numero[i]);
        }

    }
    return 0;
}
