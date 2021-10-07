#include <stdio.h>
#include <stdlib.h>

//5. Escriba una función que al recibir los valores de cantidad y monto; calcule el incremento del IVA (21%) sobre el total.

float calcularIVA(float cantidad,float monto)
{
    float iva;

    iva=((cantidad*monto)*21/100);

    return iva;
}

int main()
{
    float cantidad,monto,iva,total;

    printf("\n----------------------------------------------\n Ingrese cantidad: ");
    scanf("%f",&cantidad);
    printf("\n Ingrese monto: ");
    scanf("%f",&monto);

    total=cantidad*monto;
    iva= calcularIVA(cantidad,monto);
    printf("\n----------------------------------------------\n Compra sin iva: %.2f$ \n Iva Total: %.2f$\n Total:%.2f$ \n----------------------------------------------\n",
    total,iva,total+iva);
    return 0;
}
