#include <stdio.h>
#include <stdlib.h>

/* Crear una función que calcule cual es el menor de dos números enteros. */


int fNumeroMenor(int numUno,int numDos)
{
    int esMenor;

    if(numUno<numDos) {
        esMenor=numUno;
    }else {
        esMenor=numDos;
    }
    return esMenor;
}

int main()
{
    int numUno,numDos,esMenor;

    printf("\nIngrese 1er numero: ");
    scanf("%d",&numUno);
    printf("\nIngrese 2er numero: ");
    scanf("%d",&numDos);

    esMenor=fNumeroMenor(numUno,numDos);
    printf("\nEl menor es: %d \n",esMenor);
    return 0;
}
