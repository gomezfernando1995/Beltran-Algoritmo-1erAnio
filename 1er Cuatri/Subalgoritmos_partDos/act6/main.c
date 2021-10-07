#include <stdio.h>
#include <stdlib.h>
/*
    Crear una función que reciba un determinado número y retorne el mismo pero con el signo cambiado (de positivo a negativo y viceversa). */

int fInverso(int num)
{
    return (num*-1);
}

int main()
{
    int num;

    printf("\n Ingrese numero: ");
    scanf("%d",&num);
    num=fInverso(num);
    printf("\n  %d \n",num);

    return 0;
}
