#include <stdio.h>
#include <stdlib.h>
/*
6. Realizar un programa que pida la base y el exponente y calcule la potencia.
*/
int main()
{
    int base,exponente,result,i;
    result=1;
    printf("\n Ingrese base: ");
    scanf("%d",&base);
    printf("\n Ingrese exponente: ");
    scanf("%d",&exponente);

    for(i=0;i<exponente;i++)
    {
        result=(result)*base;
    }


    printf("\n Resultado: %d",result);
    return 0;
}
