#include <stdio.h>
#include <stdlib.h>
/*1.	Crea un programa que permita cargar valores decimales en una matriz de 4x4 valores.
        Una vez finalizada la carga, se deberán invertir los valores de la misma de acuerdo a
        su orden de carga. Visualizar ambas matrices al finalizar.  */

void load(float matrix[][4],int row,int col)
{
    int i,j;

    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("Ingrese numero: ");
            scanf("%f",&matrix[i][j]);
        }
    }
}

void show(float matrix[][4],int row,int col)
{
    int i,j;

    for(i=0; i<row; i++)
    {
        puts("\n");
        for(j=0; j<col; j++)
        {
            printf(" %d.%d[ %.f ] ",i,j,matrix[i][j]);
        }
    }
    puts("\n\n");
}

void  rotateMatrix(float matrix[][4], int row,int col)
{
    int i,j;
    float aux;

    for(i=0 ; i<row/2; i++)
    {
        for(j=0; j<col; j++)
        {
            aux=matrix[i][j];
            matrix[i][j] =matrix[3-i][3-j];
            matrix[3-i][3-j]=aux;
        }
    }
}

int main()
{
    int row=4,col=4;
    float matrix [row][col];

    load(matrix,row,col);
    show(matrix,row,col);
    rotateMatrix(matrix,row,col);
    printf("\n MATRIZ INVERTIDA");
    show(matrix,row,col);

    return 0;
}
