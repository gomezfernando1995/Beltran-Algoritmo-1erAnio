#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    3.	Conceptualice la estructura necesaria para implementar el juego tres en línea (ta-te-ti).
    Cargue los valores de cada uno de los recuadros con lo que ha cargado el usuario. Al finalizar
    la carga, determine mediante una rutina si existe un ganador o no. Tenga en cuenta que
    pueden existir valores no cargados, de acuerdo a la dinámica que se haya dado del juego.
*/
int checkData(char data)
{
    int re=0;
    if(data != 'x' && data !='o' && data !='X' && data != 'O' )
    {
        printf("\n  Error, reingrese dato!\n ");
        re=1;
    }
    return re;
}

void loadData(char matrix[][3],int row,int col)
{
    int i,j;
    char aux;

    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            do
            {
                printf(" \n %d.%d - : ",i+1,j+1);
                fflush(stdin);
                scanf("%c",&aux);
            }while(checkData(aux));

            matrix[i][j]=aux;
        }
    }
}
void showData(char matrix[][3],int row,int col)
{
    int i,j;

    for(i=0; i<row; i++)
    {
        puts("\n   ");
        for(j=0; j<col; j++)
        {
            printf(" [%c]",matrix[i][j]);
        }
    }
    puts("\n\n");
}

void winnerOrLoser(char matrix[][3],int row,int col)
{
            //HORIZONTAL
        if((matrix[0][0] == 'x' && matrix[0][1] == 'x'  && matrix[0][2] == 'x') ||
            (matrix[1][0] == 'x' && matrix[1][1] == 'x'  && matrix[1][2] == 'x') ||
            (matrix[2][0] == 'x' && matrix[2][1] == 'x'  && matrix[2][2] == 'x') ||
           //VERTICAL
            (matrix[0][0] == 'x' && matrix[1][0] == 'x'  && matrix[2][0] == 'x') ||
            (matrix[0][1] == 'x' && matrix[1][1] == 'x'  && matrix[2][1] == 'x') ||
            (matrix[0][2] == 'x' && matrix[1][2] == 'x'  && matrix[2][2] == 'x') ||
             //CRUZADO
            (matrix[0][0] == 'x' && matrix[1][1] == 'x'  && matrix[2][2] == 'x') ||
            (matrix[0][2] == 'x' && matrix[1][1] == 'x'  && matrix[2][0] == 'x'))
        {
            printf("\n\n FELICITACIONES! JUEGO GANADO!! \n\n");
        }else{
             printf("\n \n       PERDISTES! OTRA VEZ SERA!! \n");
        }
}

int main()
{
     int row=3,col=3;
    char matrix [row][col];
    printf("\n------- TA-TE-TI  ------- \n");
    loadData(matrix,row,col);
     showData(matrix,row,col);
     winnerOrLoser(matrix,row,col);

    return 0;
}
