#include <stdio.h>
#include <stdlib.h>
//1. Realice una función que determine el resultado de un cálculo de potencia
float fCalcularPotencia(int base,int potencia);

int main()
{
    int base,exponente;
    float resultado;

    printf("\n Ingrese base: ");
    scanf("%d",&base);
    printf(" Ingrese exponente: ");
    scanf("%d",&exponente);

    resultado=fCalcularPotencia(base,exponente);

    printf("\n Resultado: %.1f",resultado);
    return 0;
}

float fCalcularPotencia(int base,int potencia)
{
    int i;
    float resultado = 1;

    for(i=0; i<potencia; i++)
    {
        resultado=resultado*base;
    }
}
