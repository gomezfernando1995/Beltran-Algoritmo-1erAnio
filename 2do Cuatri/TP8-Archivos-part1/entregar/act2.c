#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *archivo;

    char caracteres[100];

    archivo = fopen("personas.csv","r");

    if (archivo == NULL)
        printf(" \nA ocurrido un error\n");
    else
    {
                puts("");

        while (feof(archivo) == 0)
        {
            fgets(caracteres,100,archivo);
            printf(" %s\n ",caracteres);
        }
        puts("");
    }
    fclose(archivo);
    return 0;
}
