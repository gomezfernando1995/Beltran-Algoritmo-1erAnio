#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5
/*
    Cargar un vector de 30 posiciones por medio de un procedimiento que solo admita la carga de
    valores F o M (femenino/masculino). En caso de que no sea alguno de esos valores
    (validar por medio de una función), deberá solicitarlo hasta que sea correcto. Al
    finalizar, visualizar (utilizando una función que reciba el vector y el valor que se
    desea obtener el porcentaje) el porcentaje equivalente a cada género.
*/

int fVericarSexo(char sexo[TAM],int i)
{
    if(sexo[i]=='m' || sexo[i]=='f')
    {
       return 1;
    }else{
        return 0;
    }
}
void pIngresarSexo(char sexo[TAM])
{
    int i;
    for(i=0;i<TAM;i++)
    {
         do
         {
            printf("----------------%d----------------------\n F -> Femenino\n M -> Masculino \n         Ingrese sexo:",i);
            scanf("%s",&sexo[i]);
            fVericarSexo(sexo,i);
         }while((fVericarSexo(sexo, i)!=1));
    }
}

float FporcentajeDeGenero(char aSexo[TAM],char tipo)
{
    int i;
    float contador=0;

    for(i=0; i<TAM; i++)
    {
        if(aSexo[i]==tipo)
        {
            contador++;
        }
    }
    return  contador/TAM*100;;
}

void submenu(char sexo[TAM])
{
    printf("\n Porcentaje del Femenino solicitado %%%.2f \n",FporcentajeDeGenero(sexo,'f'));
    printf(" Porcentaje del Masculino solicitado %%%.2f \n", FporcentajeDeGenero(sexo,'m'));
}

int main()
{
    char sexo[TAM];
    pIngresarSexo(sexo);
    submenu(sexo);
    return 0;
}
