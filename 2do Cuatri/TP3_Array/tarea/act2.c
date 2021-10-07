/*2.   Crear un vector de número enteros de 20 posiciones. En un vector paralelo,
     luego de la carga inicial, especificar en la posición equivalentes: el carácter más (+)
      si es positivo; guion si es negativo (-) y asterisco si es 0 (*). Mostrar el resultado en pantalla */

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

void pCargaVectorChar(char aEnteroChar[],int aEntero[],int tam){
    int i;
    for(i=0; i<tam; i++)
    {
        if(aEntero[i]<0)
        {
            aEnteroChar[i]='-';
        }else if(aEntero[i]>0)
        {
            aEnteroChar[i]='+';
        }else
        {
            aEnteroChar[i]='*';
        }
    }
}

void pMostrarVector(int aEnteros[],char aChar[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("\n Numero: %-4d[%c] \n",aEnteros[i],aChar[i]);
    }
}


int main()
{

    int tam=5,aEnteros[tam];
    char aChar[tam];

    pCargaDatos(aEnteros,tam);
    pCargaVectorChar(aChar,aEnteros,tam);
    pMostrarVector(aEnteros,aChar,tam);

    return 0;
}
