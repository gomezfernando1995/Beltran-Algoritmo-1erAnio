#include <stdio.h>
#include <stdlib.h>

/*Crear programa que calcule el cubo de un número real. Realícelo mediante un procedimiento.*/

void pCalcularCubo(int num)
{
    int i,resultado=1;

    for(i=0;i<3;i++)
    {
        resultado=resultado*num;
    }
    printf("\n Cubo de %d es %d \n",num,resultado);
}

int main()
{
    int numero;
    printf("\n Ingrese numero:");
    scanf("%d",&numero);
    pCalcularCubo(numero);
    return 0;
}
