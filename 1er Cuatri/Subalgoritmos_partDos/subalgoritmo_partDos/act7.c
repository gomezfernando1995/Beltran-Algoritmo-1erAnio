#include <stdio.h>
#include <stdlib.h>

/* Crear un procedimiento que reciba un valor numérico y que retorne en pantalla el resultado de su cuadrado y cubo.*/

void pCalcularCuboYCuadrado(int num)
{
    int i,resultadoCubo=1,resultadoCuadrado=1;

    for(i=0;i<3;i++)
    {
        resultadoCubo=resultadoCubo*num;
    }
     for(i=0;i<2;i++)
    {
        resultadoCuadrado=resultadoCuadrado*num;
    }
    printf("\n El Cubo de %d es %d \n",num,resultadoCubo);
    printf("\n El Cuadrado de %d es %d \n",num,resultadoCuadrado);
}

int main()
{
    int numero;
    printf("\n Ingrese numero:");
    scanf("%d",&numero);
    pCalcularCuboYCuadrado(numero);
    return 0;
}
