#include <stdio.h>
#include <stdlib.h>

/*
2. Solicite un valor numérico al usuario e informe en pantalla
el mismo valor, pero con el signo invertido (si es positivo a negativo y viceversa). */

int main()
{
   int ValorIngresado;

   printf("\nIngrese Valor: ");
   scanf("%d",&ValorIngresado);

   if(ValorIngresado>0)
   {
        printf("\n El valor ingresado es %d \n",-ValorIngresado);
   }
   else
   {
        printf("\n El valor ingresado es %d \n",-ValorIngresado);
   }
    return 0;
}
