#include <stdio.h>
#include <stdlib.h>
/*
4. Realizar un programa que pida que se dos números consecutivos (3 y 4; 9 y 10 etc.).Cuando se introducen
    tres números consecutivos dice “gracias” y termina.Mientras no seintroduzcan tres números consecutivos el
    programa sigue pidiendo números indefinidamente.
*/
int main()
{
    int numero,numeroAnterior,contadorConsecutivo;
    contadorConsecutivo=0;

    do
    {
        printf("\n Ingrese numero consecutivo:");
        scanf("%d",&numero);

        if(numero==numeroAnterior+1)
        {
            contadorConsecutivo++;
        }else{
            contadorConsecutivo=0;
        }
        numeroAnterior = numero;

    }while(contadorConsecutivo!=2);
    printf("\n Gracias, se ingresaron 3 numeros consecutivos \n ");

    return 0;
}
