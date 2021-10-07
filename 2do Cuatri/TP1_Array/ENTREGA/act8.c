#include <stdio.h>
#include <stdlib.h>
#define TAM 12

/*
  Implemente un sistema en donde se tenga previamente cargado los meses de un año dentro de un array.
  Cuando el usuario ingrese un valor numérico, se le deberá retornar el correspondiente mes. Por ejemplo 1 -> Enero.
*/

void mDatos(int dato, char cMeses[][12])
{
     printf("\n %s \n",cMeses[dato-1]);
}

int perdirDato()
{
    int auxDato;

    printf("\nIngrese el mes por el numero: ");
    scanf("%d",&auxDato);
    while(auxDato<1 || auxDato>12 )
    {
        printf("\nReingrese el mes:");
        scanf("%d",&auxDato);
    }
    return auxDato;
}

int main()
{
    int datoIngresado;
    char meses[TAM][12]= {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};

    datoIngresado = perdirDato();
    mDatos(datoIngresado, meses);

    return 0;
}

