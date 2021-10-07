#include <stdio.h>
#include <stdlib.h>
/*
2. Realizar un programa que imprima por pantalla tantos asteriscos como diga el usuario.Al ejecutarse debe preguntar
 “¿Cuantos asteriscos desea imprimir?”, leer el número queintroduce el usuario e imprimir los asteriscos.
*/
int main()
{
    int asterisco,i;

    printf("\n ¿Cuantos asteriscos desea imprimir? ");
    scanf("%d",&asterisco);
    while(asterisco<0)
    {
      printf("\n ¿Cuantos asteriscos desea imprimir? ");
      scanf("%d",&asterisco);
    }
    for(i=1;i<=asterisco;i++)
    {
        printf("\n *");
    }

    return 0;
}
