/* 1.   Crear dos vectores numéricos (solo positivos y enteros) de 10 posiciones.
        Solicitar al usuario cargar el primero. En base a dicha cargar, generar el
        contenido del segundo sin valores repetidos. */

#include <stdio.h>
#include <stdlib.h>

void pMostrar (int aNumero[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
           printf("%d \n",aNumero[i]);
    }
}

int Fverificar(int aEntero[],int i)
{
    if(aEntero[i]<0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void pCargaAutomatica(int aNumero[],int tam,int ultimoValorAgregado )
{
    int i;
    for(i=0;i<tam;i++)
    {
        aNumero[i]=ultimoValorAgregado+1;
        ultimoValorAgregado=ultimoValorAgregado+1;
    }
}

void pCargaDatos(int aEntero[],int aEnteroDos[],int tam)
{
    int i,ultimoValorAgregado;
    for(i=0; i<tam; i++)
    {
        do{
            printf("\n%d-Numero: ",i+1);
            scanf("%d",&aEntero[i]);
        }while(Fverificar(aEntero,i)==0);
        ultimoValorAgregado=aEntero[i];
    }
    pCargaAutomatica(aEnteroDos,tam,ultimoValorAgregado);
}

int main()
{
    int tam=10,aEnterosUno[tam],aEnterosDos[tam];
    pCargaDatos(aEnterosUno,aEnterosDos,tam);
    pMostrar(aEnterosUno,tam);
    printf("\n valores siguentes: \n ");
    pMostrar(aEnterosDos,tam);
    return 0;
}
