#include <stdio.h>
#include <stdlib.h>
/*
Lea 10 números por teclado, 5 para un array y 5 para otro array distinto. Mostrar los 10 números en pantalla mediante un solo array.
*/



int main()
{
    int arrayUno[5]={1,2,3,4,5};
    int arrayDos[5]={10,11,12,13,14};
    int arrayTres[10];
    int i,j=0;

    for(i=0;i<10;i++)
    {
        if(i<5)
        {
            arrayTres[i]=arrayUno[i];
        }else{
            arrayTres[i]=arrayDos[j];
            j++;
        }

        printf("%d\n",arrayTres[i]);
    }
    return 0;
}
