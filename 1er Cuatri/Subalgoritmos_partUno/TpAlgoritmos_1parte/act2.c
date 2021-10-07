#include <stdio.h>
#include <stdlib.h>
/*
    2. Escribir un programa que, utilizando funciones con parámetros, lea desde el teclado las unidades y el
     precio que quiere comprar, y en función de las unidades introducidas le haga un descuento o no
    (cuando las unidades excedan media docena se aplicará 4% y el 10% cuando excedan la docena)
*/

int fPorcentaje(int unidades)
{
    int resultado;

    if(unidades<7) {
        resultado=0;
    }else if(unidades>12) {
        resultado=10;
    }else {
        resultado=4;
    }
    return resultado;
}

int main()
{
    float precio,total;
    int unidades,porcentaje;

    unidades=-1;
    precio=-1;

    while(unidades<0) {
        printf("\n Ingrese unidades: ");
        scanf("%d",&unidades);
    }
    while(precio<0) {
        printf("\n Ingrese precio: ");
        scanf("%f",&precio);
    }
    porcentaje= fPorcentaje(unidades);
    total=precio-((precio*porcentaje)/100);

    printf("\n Precio: %.2f   Precio Total: %.2f",precio,total);
    return 0;
}
