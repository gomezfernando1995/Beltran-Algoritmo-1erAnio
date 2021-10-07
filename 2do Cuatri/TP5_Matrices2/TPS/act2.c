#include <stdio.h>
#include <stdlib.h>
/*
    2.	Cargue los datos de una matriz numérica de 6x3. No permita que se ingrese el valor 0.
    Una vez finalizada la carga, deberá reemplazar cada valor por su opuesto (signo cambiado).
    Visualice el resultado final en pantalla.
*/

int checkData(int data)
{
    int re=0;
    if(data==0)
    {
        printf("\n  Error, reingrese dato!\n ");
        re=1;
    }
    return re;
}


void loadData(int matrix[][3],int row,int col)
{
    int i,j,aux;

    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            do
            {
                printf(" \n %d.%d - Ingrese numero: ",i+1,j+1);
                scanf("%d",&aux);
            }
            while(checkData(aux));
            matrix[i][j]=aux;
        }
    }
}

void invertNumber(int matrix[][3],int row,int col)
{
    int i,j;

    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
                matrix[i][j] =matrix[i][j]*(-1);
        }
    }
}

void showData(int matrix[][3],int row,int col)
{
    int i,j;

    for(i=0; i<row; i++)
    {
        puts("\n");
        for(j=0; j<col; j++)
        {
            printf(" %d.%d-[%-3.d] ",i+1,j+1,matrix[i][j]);
        }
    }
    puts("\n\n");
}

int main()
{
    int row=6,col=3;
    int matrix [row][col];

    loadData(matrix,row,col);
    showData(matrix,row,col);
    invertNumber(matrix,row,col);
    showData(matrix,row,col);

    return 0;
}
