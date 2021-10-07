#include <stdio.h>
#include <stdlib.h>

/* Crear un procedimiento que reciba un valor numérico y que retorne en pantalla el resultado de su cuadrado y cubo.*/

float fPotencia(int valor,float exponente){
    int i;
    float resultado=1;

    for(i=0;i<exponente;i++) {
        resultado=resultado*valor;
    }
    return resultado;
}


void pCalcularCuboYCuadrado(int num)
{
    printf("\n El Cubo de %d es %.f \n",num,fPotencia(num,3));
    printf("\n El Cuadrado de %d es %.f \n",num,fPotencia(num,2));
}



int main()
{
    int numero;
    printf("\n Ingrese numero:");
    scanf("%d",&numero);
    pCalcularCuboYCuadrado(numero);
    return 0;
}



