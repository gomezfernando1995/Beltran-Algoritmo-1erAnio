#include <stdio.h>
#include <stdlib.h>
/*
   El usuario introduce tres números enteros y el programa se encargará de decir cuál de los tres es el central o el de en medio. Realícelo mediante función.
*/

int fNumeroIntermedio(int numUno, int numDos,int numTres)
{
    int numeroMedio;

    if(numUno>numDos && numUno<numTres) {
        numeroMedio=numUno;
    }else if(numDos<numTres && numDos>numUno) {
        numeroMedio=numDos;
    }else {
        numeroMedio=numTres;
    }

    return numeroMedio;
}


int main()
{
    int numUno, numDos, numTres,numeroMedio;

    printf("\n Ingrese num uno: ");
    scanf("%d",&numUno);
    printf("\n Ingrese num dos: ");
    scanf("%d",&numDos);
    printf("\n Ingrese num tres: ");
    scanf("%d",&numTres);

    numeroMedio=fNumeroIntermedio(numUno,numDos,numTres);
    printf("\n El numero intermedio es : %d \n",numeroMedio);
    return 0;
}
