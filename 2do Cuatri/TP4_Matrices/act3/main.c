#include <stdio.h>
#include <stdlib.h>

/*3.   Se quiere almacenar los números de los jugadores de fútbol que salen a la
    cancha en un partido para ambos equipos. Genere la carga y visualización de la información,
    procurando que no existan valores repetidos en el mismo equipo al momento de la carga  */

int verificarNumeroRepetido(int array[][11],int fila,int columna,int numAverificar)
{
    int i, retorno=1;

    for(i=0;i<=columna;i++)
    {
        if(numAverificar==array[fila][i])
        {
            puts("\n  Error,Ya existe!!");
            retorno= 0;
        }
    }
    return retorno;
}

 void pSolicitarDatos(int cargarMatriz[][11],int fila,int columna)
{
    int i,j,valorAVerificar;

     for(i=0;i<fila;i++)
    {   puts("");
        for(j=0;j<columna;j++)
        {
            do{
                 printf(" \n [Equipo %d]\n     Que numero tendra el jugador %d: ",i+1,j+1);
                 scanf("%d",&valorAVerificar);

            }while(verificarNumeroRepetido(cargarMatriz,i,j,valorAVerificar)==0);
            cargarMatriz[i][j]=valorAVerificar;
        }
    }
}

void pMostrarDatos(int mostrarMatriz[][11],int fila,int columna)
{
    int i,j;

     for(i=0;i<fila;i++)
    {   printf("\n[Equipo %d]\n",i+1);
        for(j=0;j<columna;j++)
        {
            printf("  Jugador %d: N%d \n",j+1,mostrarMatriz[i][j]);
        }
    }
    puts("");
}

int main()
{
    int fila=2,columna=11,totalJugadores[fila][columna];

    pSolicitarDatos(totalJugadores,fila,columna);
    pMostrarDatos(totalJugadores,fila,columna);

    return 0;
}
