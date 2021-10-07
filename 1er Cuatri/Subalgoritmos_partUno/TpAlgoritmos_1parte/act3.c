#include <stdio.h>
#include <stdlib.h>
/*
     3. Escriba un procedimiento que reciba un número del 1 al 10 y muestre
     por pantalla el número escrito en números romanos
*/

void pNumeroRomano(int numero)
{
    switch(numero)
    {
    case 1:
        printf("\n I\n");
        break;
    case 2:
        printf("\n II\n");
        break;
    case 3:
        printf("\n III\n");
        break;
    case 4:
        printf("\n IV\n");
        break;
    case 5:
        printf("\n V\n");
        break;
    case 6:
        printf("\n VI\n");
        break;
    case 7:
        printf("\n VII\n");
        break;
    case 8:
        printf("\n VIII\n");
        break;
    case 9:
        printf("\n IX\n");
        break;
    case 10:
        printf("\n X\n");
        break;
    }
}


int main()
{
    int numero;

    printf("\n         Convertidor a Entero a Romano\n\n"" Ingrese numero entre 1 y 10: ");
    scanf("%d",&numero);
    while(numero<1 || numero>10)
    {
        printf("\n Error,Reingrese numero entre 1 y 10: ");
        scanf("%d",&numero);
    }
    pNumeroRomano(numero);
    return 0;
}
