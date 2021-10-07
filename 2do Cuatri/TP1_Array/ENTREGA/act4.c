#include <stdio.h>
#include <stdlib.h>

/*Lea 5 números por teclado, los copie a otro array multiplicados por 2 y muestre el segundo array. */

int main()
{
    int i,aNumeros[5];
    int aNumerosDos[5];

    for(i=0;i<5;i++)
    {
        printf("\nNumero? ");
        scanf("%d",&aNumeros[i]);

        aNumerosDos[i]=aNumeros[i]*2;
        printf("\n|  %d   |\n",aNumerosDos[i]);
    }
    return 0;
}
