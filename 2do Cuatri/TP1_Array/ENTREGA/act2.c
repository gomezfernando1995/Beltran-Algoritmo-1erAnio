#include <stdio.h>
#include <stdlib.h>

/*
Lea 20 números por teclado, almacénelos en un array y muestre la suma de todos los valores, junto con el promedio.
*/

int main()
{
    int numeros[20];
    int suma=0;
    int i;
    float promedio;

    for(i=1; i<=20; i++)
    {
        numeros[i]=5;
        suma+=numeros[i];
    }
    promedio=suma/20;

    printf("suma : %d \npromedio : %.1f \n",suma,promedio);
    return 0;
}
