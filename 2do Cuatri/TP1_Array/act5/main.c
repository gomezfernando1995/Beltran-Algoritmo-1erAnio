#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_NOM 12


/*
     Rellene un array con 12 nombres de personas. Luego, solicite por
     teclado un determinado nombre y compruebe si existe o no dentro del array.
*/

int main()
{
    char nombres[TAM_NOM][TAM_NOM]={"jorge","pepe","brian","messi","ronaldo","aguero","lionel","romario","pele","diego","roman","juan"};
    int i;
    char nombre[10];

    printf("\n Ingrese Nombre a buscar: ");
    gets(nombre);

     for(i=0;i<TAM_NOM;i++)
    {
        if(!strcmp(nombre,nombres[i]))
        {
            printf("\n Encontrado en la posicion %d \n",i+1);
        }
    }

    return 0;
}
