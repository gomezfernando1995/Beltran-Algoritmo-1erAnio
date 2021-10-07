#include <stdio.h>
#include <stdlib.h>

/*
     Desarrollá el juego “Adivine el número”: A partir de un número “inventado” por el programa, el usuario
    ingresará otro número entero tantas veces como sea necesario, hasta que el número ingresado coincida con el
    inventado por el programa. Para “inventar” el número se usará el programa de ejemplo de más abajo para la
    generación de un número al azar (note que existe un mínimo y un máximo para determinar el rango).
    En cada intento del usuario, el número se comparará con el número inventado, indicando por pantalla si es
    mayor o menor al otro. Si ambos números coinciden se saldrá del ciclo y se felicitará al usuario, informando,
    además, cuántos intentos necesitó para acertar.
*/
int main()
{
    int numeroIngresado=0;
    int iMinimo = 1;
    int iMaximo = 10;

    int iAlAzar = 0;
    srand(time(NULL));
    iAlAzar = rand() % iMaximo;

    do
    {
        printf("\n Ingrese numero: ");
        scanf("%d",&numeroIngresado);

        if(numeroIngresado<iAlAzar)
        {
            printf("\n Falta..\n");
        }else if(numeroIngresado>iAlAzar)
        {
            printf("\n Te pasates...\n");
        }else if(numeroIngresado==iAlAzar){
            printf("\n Felicitaciones !! Ganastes \n");
        }

    }while(numeroIngresado!=iAlAzar);

        printf("\n \Número al azar = %d\n", iAlAzar);

    return 0;

}
