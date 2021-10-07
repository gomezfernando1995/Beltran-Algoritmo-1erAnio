#include <stdio.h>
#include <stdlib.h>

/*
9. Que calcule el sueldo que le corresponde al trabajador de una empresa según su sueldo bruto
(sin deducciones).El programa debe realizar los cálculos en función de los siguientes criterios:
    a. Si lleva más de 10 años en la empresa se le aplica un aumento del 10%.
    b. Si lleva menos de 10 años pero más que 5 se le aplica un aumento del 7%.
    c. Si lleva menos de 5 años pero más que 3 se le aplica un aumento del 5%.
    d. Si lleva menos de 3 años se le aplica un aumento del 3%.
*/
int main()
{
    int anios;
    float sueldoBruto,sueldoTotal;

    printf("\nIngrese su sueldo bruto: ");
    scanf("%f",&sueldoBruto);
    while(sueldoBruto<1)
    {
        printf("\nReingrese su sueldo bruto: ");
        scanf("%f",&sueldoBruto);
    }
    printf("\nIngrese año en la empresa: ");
    scanf("%d",&anios);
    while(anios<0 || anios>40)
    {
        printf("\nReingrese sus años en la empresa: ");
        scanf("%d",&anios);
    }

    if(anios>=11)
    {
        sueldoTotal = sueldoBruto*1.10;
    }
    else if (anios>=6)
    {
        sueldoTotal=sueldoBruto*1.07;
    }
    else if(anios>=3)
    {
        sueldoTotal=sueldoBruto*1.05;
    }
    else
    {
        sueldoTotal=sueldoBruto*1.03;
    }

    printf("\nTu sueldo final por tener %d años en la empresa, es %.2f$\n",anios,sueldoTotal);

    return 0;
}
