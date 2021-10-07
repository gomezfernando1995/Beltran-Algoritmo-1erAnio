#include <stdio.h>
#include <stdlib.h>
#define TAM 20

/*Crear un procedimiento que sea capaz de inicializar
(cargar todos los valores de un vector) con un determinado valor.*/


void cargaDeValores(int vector[],int numero)
{
    int i;
    for(i=0;i<TAM;i++)
    {
        vector[i]=numero;
    }
}

int main()
{
    int numeros[TAM];
    int numero,i;

    printf("Ingrese valor con el que desea rellenar el vector: ");
    scanf("%d",&numero);
    cargaDeValores(numeros,numero);
    for(i=0;i<TAM;i++)
    {
        printf("%d)%d\n",i,numeros[i]);
    }
    return 0;
}
