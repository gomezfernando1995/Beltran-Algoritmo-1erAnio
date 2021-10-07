#include <stdio.h>
#include <stdlib.h>

/*
    4.  Cargar valores numéricos en una matriz de 5x5. Los valores a cargar
    tienen que ser pares (positivos o negativos). Una vez finalizada la carga
    de valores, visualice la matriz en forma de fila/columna. Luego, reemplace los
    valores negativos por 0 y vuelva a informar.

*/

int verificarNumero(int valor)
{
    if(valor%2!=0)
    {
        puts("\n            Error, impar...");
        return 0;
    }
    return 1;
}

 void pSolicitarDatos(int cargarMatriz[][5],int fila,int columna)
{
    int i,j,valorAVerificar;

     for(i=0;i<fila;i++)
    {   puts("------------------------------------------------------");
        for(j=0;j<columna;j++)
        {
            do{
                 printf("  [%d.%d] Ingrese solo valores par: ",i+1,j+1);
                 scanf("%d",&valorAVerificar);

            }while(verificarNumero(valorAVerificar)==0);
            cargarMatriz[i][j]=valorAVerificar;
        }
    }
}

void pMostrarDatos(int mostrarMatriz[][5],int fila,int columna)
{
    int i,j;

     for(i=0;i<fila;i++)
    {   puts("");
        for(j=0;j<columna;j++)
        {
            printf("  [%-3d]",mostrarMatriz[i][j]);
        }
    }
    puts("");
}

void cambiarValoresNegativos(int matriz[][5],int fila,int columna)
{
    int i,j;
    for(i=0;i<fila;i++)
    {
        for(j=0;j<columna;j++)
        {
            if(matriz[i][j]<0)
            {
                matriz[i][j]=0;
            }
        }
    }
}

int main()
{

    int fila=5,columna=5,matriz[5][5];

    pSolicitarDatos(matriz,fila,columna);
    pMostrarDatos(matriz,fila,columna);
    cambiarValoresNegativos(matriz,fila,columna);
    pMostrarDatos(matriz,fila,columna);

    return 0;
}
