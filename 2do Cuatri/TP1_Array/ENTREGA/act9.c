#include <stdio.h>
#include <stdlib.h>
#define TAM 12

/*
  Modificar el punto anterior, para que el usuario elija el idioma (ingles o castellano) que se requiere informar el valor del mes.
*/

void mDatos(int dato, char cMeses[][12])
{ 
   printf("\n %s \n",cMeses[dato-1]);
}

int menu()
{
    int opcion;
    printf("\n----------------------------------------------------------\n");
    printf(" \n 1-Espaniol \n 2-Ingles \n 3-Salir \n\n -Ingrese opcion: ");
    scanf("%d",&opcion);
    printf("\n----------------------------------------------------------\n");

    return opcion;
}

int perdirDato(char mensaje[20])
{
    int auxDato;

    printf("\n%s",mensaje);
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
    int datoIngresado,opcion;
    char mesesSpanish[TAM][12]= {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
    char mesesEnglish[TAM][12]= {"January","February","March","April","May","June","July","August","September","October","November","December"};

    do
    {
        opcion=menu();
        switch(opcion)
        {
        case 1:
            datoIngresado = perdirDato(" Ingrese numero del mes: ");
            mDatos(datoIngresado, mesesSpanish);

            break;
        case 2:
            datoIngresado = perdirDato(" Enter number of the month: ");
            mDatos(datoIngresado, mesesEnglish);
            break;
        }
    }
    while(opcion!=3);

    return 0;
}
