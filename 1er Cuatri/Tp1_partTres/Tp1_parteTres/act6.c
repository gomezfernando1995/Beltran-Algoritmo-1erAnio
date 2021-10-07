#include <stdio.h>
#include <stdlib.h>
/*
  Realizá un programa que permita ingresar la estatura (en metros con decimales) de cada jugador de un equipo
  de baloncesto. La carga finalizará al ingresar cero. Calcular y mostrar la estatura promedio del equipo.
*/

int main()
{
    float altura,acumAltura,promedio;
    int i=0;
    altura =1;
    acumAltura=0;
    promedio=0;

    do
    {
        printf("Ingrese altura o 0 para salir: ");
        scanf("%f",&altura);
        while(altura<0 || altura>300)
        {
            printf("Reingrese altura o 0 para salir: ");
            scanf("%f",&altura);
        }
        if(altura>0)
        {
            acumAltura+=altura;
            i++;
        }
    }
    while(altura!=0);

    if(i>0)
    {
        promedio = acumAltura/i;
        printf("\n El promedio de la altura: %.1fMts . altura ingresadas: %d \n",promedio,i);
    }
    else
    {
        printf(" \nNo se ingresaron alturas \n");
    }
    return 0;
}
