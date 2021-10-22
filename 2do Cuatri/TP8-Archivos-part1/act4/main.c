#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
4. Crear dos archivos:
	.: Paises.txt ' Con el contenido de los países de Latinoamérica
	.: Provincias.txt ' Con el contenido de las provincias de Argentina

Crear un programa que le pregunte al usuario si quiere ver los países o provincias, de acuerdo a su selección, debe mostrar su contenido en pantalla (que elija 1 o 2 con el teclado).

*/

int main()
{
	FILE* fichero;
	int opcion;
	char nombreArchivo[50];
	char caracteres[500];

   	printf("\n1. Paises de Latinoamerica \n");
   	printf("2. Provincias de Argentina \n");
   	printf("\n    Ingrese el archivo que desea visualizar:  ");

   	scanf("%d", &opcion);

   	switch (opcion) {
   		case 1:
		   strcpy(nombreArchivo,"Paises.txt");
		   break;
   		case 2:
		   strcpy(nombreArchivo,"Provincias.txt");
		   break;
	}
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
            printf("%s", caracteres);
        }
    }
    fclose(fichero);

}
