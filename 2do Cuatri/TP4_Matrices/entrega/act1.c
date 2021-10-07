/*
1.
Crear una matriz de 3x4. Cargar los valores por parte del usuario.
Al finalizar muestre su contenido en pantalla en un formato de filas y columnas.
Determine cuál es el valor más grande y más bajo que se ha cargado y su posición
(coordenada).
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valores[3][4];
    int i, j;

    int valorBajo, valorAlto;
    int iBajo = 0, jBajo = 0, iAlto = 0, jAlto = 0;


    for (i=0; i < 3; i++)
    {
        for (j=0; j < 4; j++)
        {
            printf("Ingrese el valor [%d][%d]: ", i, j);
            scanf("%d", &valores[i][j]);

            if (0 == i && 0 == j)
            {
                valorBajo = valores[0][0];
                valorAlto = valores[0][0];
            }
            else
            {
                if (valorBajo > valores[i][j])
                {
                    valorBajo = valores[i][j];
                    iBajo = i;
                    jBajo = j;
                }
                if (valorAlto < valores[i][j])
                {
                    valorAlto = valores[i][j];
                    iAlto = i;
                    jAlto = j;
                }
            }
        }
    }

    for (i=0; i < 3; i++)
    {
        for (j=0; j < 4; j++)
        {
            printf("[%d]\t", valores[i][j]);
        }
        printf("\n");
    }

    printf("El valor más bajo es [%d][%d]: %d \n", iBajo, jBajo, valorBajo);
    printf("El valor más alto es [%d][%d]: %d \n", iAlto, jAlto, valorAlto);

}
