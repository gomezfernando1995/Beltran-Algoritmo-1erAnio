#include <stdio.h>
#include <stdlib.h>
#define CANT_DIA 7

/*
    PRIMER PARCIAL

    Alumno:Gomez Fernando Gabriel
    Curso: 1ro 1ra.
*/

void pValidarMonto(float* num)
{
    while(*num<0 || *num>100000)
    {
        printf("\n  Error, reingrese monto: ");
        scanf("%f",num);
    }
}

void pMontoIngresado(float* venta)
{
    float auxVenta=0;

    scanf("%f",&auxVenta);
    pValidarMonto(&auxVenta);
    *venta=auxVenta;
}

void pCargaDeMontoPorDia(float* venta)
{
    int i;
    float auxVenta=0;

    for(i=0; i<CANT_DIA; i++)
    {
        printf("\n Ingrese el monto vendido el día");

        if(i==0) {
            printf(" Lunes: ");
            pMontoIngresado(&auxVenta);
            *venta=auxVenta;
        }
        if (i==1) {
            printf(" Martes: ");
           pMontoIngresado(&auxVenta);
            *venta+=auxVenta;
        }
        if (i==2) {
            printf(" Miercoles: ");
            pMontoIngresado(&auxVenta);
            *venta+=auxVenta;        }
        if (i==3) {
            printf(" Jueves: ");
            pMontoIngresado(&auxVenta);
            *venta+=auxVenta;
        }
        if (i==4) {
            printf(" Viernes: ");
            pMontoIngresado(&auxVenta);
            *venta+=auxVenta;
        }
        if (i==5) {
            printf(" Sabado: ");
            pMontoIngresado(&auxVenta);
            *venta+=auxVenta;
        }
        if (i==6) {
            printf(" Domingo: ");
            pMontoIngresado(&auxVenta);
            *venta+=auxVenta;
        }
    }

}

int fObtenerPorcentajeComision(float venta)
{
    float comision;

    if(venta>40000) {
        comision=15;

    }
    else if (venta>20000) {
        comision=10;
    }
    else if (venta>10000) {
        comision=5;
    }
    else {
        comision=0;
    }
    return comision;
}

float fObtenerTotalComision(float totalVenta)
{
         int comision=0;
         float total=0;

         comision= fObtenerPorcentajeComision(totalVenta);

         if(comision==15)
         {
            total = totalVenta*0.15;
         }else if(comision==10)
         {
            total = totalVenta*0.10;
         }else if(comision==5)
         {
            total = totalVenta*0.05;
         }

    return total;
}

void pVisualizarResultado(float totalVentas, int porcentajeComision, float totalComision)
{
    printf("\n----------------------------------------------------------------------------------------");
    printf("\n El total acumulado de ventas ha sido $ %.2f.\n El porcentaje de comisión obtenida es de %d%%  cuyo monto de comisión equivale a: $ %.2f \n ",totalVentas,porcentajeComision,totalComision);
    printf("----------------------------------------------------------------------------------------\n\n | 1er Parcial Gomez Fernando  |\n");
}


int main()
{
    float totalVenta=0, totalComision=0;
    int porcentajeComision;

    pCargaDeMontoPorDia(&totalVenta);
    porcentajeComision=fObtenerPorcentajeComision(totalVenta);
    totalComision = fObtenerTotalComision(totalVenta);
    pVisualizarResultado(totalVenta,porcentajeComision,totalComision);

    return 0;
}
