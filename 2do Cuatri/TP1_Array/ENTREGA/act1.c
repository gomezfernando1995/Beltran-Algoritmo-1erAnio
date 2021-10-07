#include <stdio.h>
#include <stdlib.h>

/*
 Realice un programa que rellene un array con los 100 primeros números enteros de forma consecutiva.
 Luego, visualice el resultado de forma ascendente y descendente.
*/

int main()
{
    int aNumeros[100];
    int i;

    for(i=1;i<=100;i++)
    {
        aNumeros[i]=i;
        printf("%d\n",aNumeros[i]);

    }
    printf("------------------------------------------------------------------------------------------\n");
    for(i=100;i>=1;i--)
    {
        aNumeros[i]=i;
        printf("%d\n",aNumeros[i]);
    }


    return 0;
}
