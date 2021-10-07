#include <stdio.h>
#include <stdlib.h>

/*Crea un array de 15 posiciones de números con valores pedidos por
 teclado. Muestre al final el indice y el valor al que corresponde.
  Haga dos procedimientos: uno para rellenar valores y otro para mostrar. */

void pCargaDeNumero(int aNumeros[],int aIndice[],int tam,char* mensaje)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("\n %s",mensaje);
        scanf("%d",&aNumeros[i]);
        aIndice[i]=i;
    }
}

void pMostrarDatos(int aNumeros[],int aIndice[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("\n En el lugar %d se ingreso n %d \n",aIndice[i],aNumeros[i]);
    }
}


int main()
{
    int tam=15,aNumeros[tam],aIndice[tam];

    pCargaDeNumero(aNumeros,aIndice,tam,"Ingrese Numero: ");
    pMostrarDatos(aNumeros,aIndice,tam);

    return 0;
}
