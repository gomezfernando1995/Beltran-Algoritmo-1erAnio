#include <stdio.h>
#include <stdlib.h>

//2.       Crear una estructura que permita la carga de las tablas de multiplicar y su correspondiente resultado (del 1 al 9).

void pSolicitarDatos(int cargarMatriz[][10],int fila,int columna)
{
    int i,j;

     for(i=0;i<fila;i++)
    {   puts("");
        for(j=0;j<columna;j++)
        {
            printf(" %dx%d= ",i+1,j+1);
            scanf("%d",&cargarMatriz[i][j]);
        }
    }
}

void pMostrarDatos(int mostrarMatriz[][10],int fila,int columna)
{
    int i,j;

     for(i=0;i<fila;i++)
    {   puts("");
        for(j=0;j<columna;j++)
        {
            printf(" %dx%d=%-2d ",i+1,j+1,mostrarMatriz[i][j]);
        }
    }
    puts("");
}

int main()
{
    int fila=2,columna=10;
    int tablasDeMultiplicar[fila][columna];

    pSolicitarDatos(tablasDeMultiplicar,fila,columna);
    pMostrarDatos(tablasDeMultiplicar,fila,columna);

    return 0;
}


