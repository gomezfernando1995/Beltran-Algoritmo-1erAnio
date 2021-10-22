#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
3. Genere  un programa que pregunte un nombre de archivo (ubicación) y muestre en pantalla el contenido de ese archivo.
*/

int main()
{
	FILE* fichero;
	char nombreArchivo[255];
	char caracteres[500];

   	printf("\n Ingrese el nombre el archivo: ");
   	scanf("%[^\n]s", &nombreArchivo);

   	fichero = fopen(nombreArchivo,"r");

    if (fichero == NULL)
    {
        printf("El archivo %s no existe", nombreArchivo);
    }
    else
    {
        while (feof(fichero) == 0)
        {
            fgets(caracteres, 100, fichero);
            printf("%s\n", caracteres);
        }
    }
    fclose(fichero);

}
