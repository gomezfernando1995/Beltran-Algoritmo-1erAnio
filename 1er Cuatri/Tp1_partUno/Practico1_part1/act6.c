#include <stdio.h>
#include <stdlib.h>
/*
  6. Solicitar números indefinidamente hasta que se ingrese un 0 (cero), luego mostrar el promedio de todos ellos
*/

int main()
{
    int numeroIngresado,contadorNumero,acumuladorNumero,promedio;
    acumuladorNumero=0;
    contadorNumero=0;

    while(numeroIngresado!=0)
    {
        printf("\nIngrese numero o ingrese 0 para terminar: ");
        scanf("%d",&numeroIngresado);
        acumuladorNumero+=numeroIngresado;
        contadorNumero++;
    }
    promedio = acumuladorNumero/contadorNumero;
    printf("\n   Suma de N°ingresados: %d     Promedio: %d \n",acumuladorNumero,promedio);
    return 0;
}
