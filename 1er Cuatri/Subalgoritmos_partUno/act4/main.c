#include <stdio.h>
#include <stdlib.h>
/* . Escriba un procedimiento que reciba dos valores
    numéricos y retorne mediante sus parámetros, el resultado
   de la multiplicación y la división entre ambos valores
*/

float calculoPorParametro(float numUno,float numDos,float* resultadoDivision,int* resultadoMulti)
{
    *resultadoMulti=numUno*numDos;
    if(numDos==0) {
        *resultadoDivision=0;
    }
    else
    {
        *resultadoDivision=numUno/numDos;
    }
}

int main()
{
    float numUno,numDos,resultadoDivision;
    int resultadoMultiplicacion;

    printf("\nIngrese primer valor: ");
    scanf("%f",&numUno);
    printf("\nIngrese segundo valor: ");
    scanf("%f",&numDos);

    calculoPorParametro(numUno,numDos,&resultadoDivision, &resultadoMultiplicacion);

    if (resultadoDivision==0){
        printf("\n Resultado Division: No se puede dividir por 0\n Resultado Multiplicacion: %d \n",resultadoMultiplicacion );
    }
    else {
        printf("\n Resultado Division: %.1f \n Resultado Multiplicacion: %d \n",resultadoDivision,resultadoMultiplicacion );
    }
    return 0;
}



