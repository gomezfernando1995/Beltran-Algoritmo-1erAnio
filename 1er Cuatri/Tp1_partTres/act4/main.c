#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
/*
    4. Realizá un programa que permita ingresar una edad (entre 1 y 120 años) y un género ('F' para mujeres, 'M' para hombres).
    En caso de haber ingresado valores erróneos (edad fuera de rango o género inválido), informar tal situación.
    Si los datos están bien ingresados el programa debe indicar, sabiendo que las mujeres se jubilan con 60 años o más y los
    hombres con 65 años o más, si la persona está en edad de jubilarse.
*/
int main()
{
    int age,ageLeft;
    char gender;

    printf("\n Ingrese edad: ");
    scanf("%d",&age);
    while(age<1 || age>120)
    {
        printf("\n !! Error,Reingrese edad: ");
        scanf("%d",&age);
    }

    printf(" Ingrese genero 'F' mujer, 'M' hombre: ");
    __fpurge(stdin);
    scanf("%c",&gender);
    while(!(gender=='F' || gender=='M'))
    {
        printf("\n !! Error,reingrese genero 'F' mujer, 'M' hombre: ");
        __fpurge(stdin);
        scanf("%c",&gender);
    }

    if(gender == 'M')
    {
        if(age>=65)
        {
            printf("\n- Se puede jubilar  -\n");
        }
        else {
            ageLeft=65-age;
            printf("\n-  No se puede jubilar le faltan %d anios  -\n",ageLeft);
        }
    }

    if(gender == 'F')
    {
        if(age>=60)
        {
            printf("\n- Se puede jubilar  -\n");
        }
        else {
            ageLeft=60-age;
            printf("\n-  No se puede jubilar le faltan %d anios -\n",ageLeft);
        }
    }

    return 0;
}
