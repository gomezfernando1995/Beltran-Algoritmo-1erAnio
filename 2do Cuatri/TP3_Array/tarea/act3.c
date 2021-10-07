/*  Escriba un programa que dado un vector
 de valores numéricos, pueda detectar cuáles
 son los dos valores más pequeños que se han almacenado.  */

#include <stdio.h>
#include <stdlib.h>

void pCargaDatos(int aEntero[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("\n %d-Numero: ",i+1);
        scanf("%d",&aEntero[i]);
    }
}

void pValoresMasBajos(int aNumeros[],int* valorUno,int* valorDos,int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        if(i==0)
        {
            *valorUno=aNumeros[i];
            *valorDos=aNumeros[i];
        }
         if(aNumeros[i]<*valorUno)
        {
          *valorUno=aNumeros[i];
        }
        else if(aNumeros[i]<*valorDos)
        {
           *valorDos=aNumeros[i];
        }
    }
}

int main()
{
    int tam=5,valorUno,valorDos,aNumeros[tam];

    pCargaDatos(aNumeros,tam);
    pValoresMasBajos(aNumeros,&valorUno,&valorDos,tam);
    printf("\n Valores Mas bajo %d  -  %d\n ",valorUno,valorDos);

    return 0;
}
