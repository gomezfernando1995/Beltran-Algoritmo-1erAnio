#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3
/*
1. Tres personas aportan diferente capital a una sociedad y desean saber
qué porcentaje del total aportó cada una (indicando nombre y porcentaje) y cuál es el monto del total aportado entre las tres.
Para resolverlo, solicitá la carga por teclado del nombre y el capital aportado por cada una de las tres personas. El programa
debe mostrar lo pedido en el siguiente formato:
Nombre: ………………., Capital aportado: $ …. , Porcentaje del capital: %....Monto total aportado: $ ……..
*/

int main()
{
    char nombre [TAM][20];
    float capital[TAM];
    float porcentajeCapital[TAM];
    float acumuladorCapital;
    int i;

    for(i=0; i<TAM; i++)
    {
        printf(" Ingrese nombre: ");
        scanf("%s",nombre[i]);

        printf(" Ingrese su capital: ");
        scanf("%f",&capital[i]);
        printf("\n");

        acumuladorCapital +=capital[i];
    }
    for(i=0; i<TAM; i++)
    {
        porcentajeCapital[i] = (capital[i]/acumuladorCapital)*100;
        printf("\n Nombre: %s | Capital aportado: $%.0f | Porcentaje del capital: %.1f % | Monto total aportado: %.0f$ \n"
               ,nombre[i],capital[i],porcentajeCapital[i],acumuladorCapital);
    }

    return 0;
}
