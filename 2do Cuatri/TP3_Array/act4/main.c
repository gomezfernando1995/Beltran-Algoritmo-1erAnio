#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 4.   Cargar un vector con 10 valores numéricos enteros.
       Luego de su carga, informar si son pares o impares
       cada uno de sus elementos (utilice una función para tal fin).
*/



int FparOimpar(int valores[],int i)
{
    int retorno=-1;

    if(valores[i]% 2==0)
    {
        retorno=1;
    }else{
        retorno=2;
    }
    return retorno;
}
void pCargaDatos(int aEntero[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%d-Numero: ",i+1);
        scanf("%d",&aEntero[i]);
    }
}

void pVerificarNumero(char parOimpar[][6],int valoresEnteros[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(FparOimpar(valoresEnteros,i)==1)
        {
            strcpy(parOimpar[i],"Par");
        }else{
            strcpy(parOimpar[i],"Impar");
        }
    }
    printf("\n");
}

void pMostrarNumero (char parOimpar[][6],int valoresEnteros[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
           printf(" %-2d -%s \n",valoresEnteros[i],parOimpar[i]);
    }
}

int main()
{

    int tam=10,valoresEnteros[tam];
    char parOimpar[tam][6];

    pCargaDatos(valoresEnteros,tam);
    pVerificarNumero(parOimpar,valoresEnteros,tam);
    pMostrarNumero(parOimpar,valoresEnteros,tam);

    return 0;
}
