/*
    Crear dos vectores de 10 posiciones del tipo string.
    Una vez que se hayan cargado ambos, deberá verificar si cada uno
    de los valores del primero se encuentra en alguna posición del otro. Informe el resultado.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PcargaDeString(char array[],int tam,char* mensaje)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%s",mensaje);
        scanf("%s",&array[i]);
    }
}

int FverificacionDeArray(char arrayUno[],char arrayDos[],int tam,int posicionEncontrado[],char aCaracterQueSeRepite[])
{
    int i,contador=0;

    for(i=0;i<tam;i++)
    {
        if(arrayUno[i]==arrayDos[i])
        {
            aCaracterQueSeRepite[i]=arrayUno[i];
            posicionEncontrado[i]=i;
            printf("\n Se encontro coincidencia en la posicion %d con el caracter %c \n ",1+posicionEncontrado[i],aCaracterQueSeRepite[i]);
            contador=1;
        }
    }
    return contador;
}

int main()
{
    int Tam=3, posicionEncontrado[Tam];
    char aVectorUno[Tam], aVectorDos[Tam],aCaracterQueSeRepite[Tam];

    PcargaDeString(aVectorUno,Tam,"\n Array Uno- ingrese dato:");
    PcargaDeString(aVectorDos,Tam,"\n Array dos- ingrese dato:");
    if(!FverificacionDeArray(aVectorUno,aVectorDos,Tam,posicionEncontrado,aCaracterQueSeRepite))
    {
        printf("\n No se encontraron caracteres iguales\n");
    }


    return 0;
}
