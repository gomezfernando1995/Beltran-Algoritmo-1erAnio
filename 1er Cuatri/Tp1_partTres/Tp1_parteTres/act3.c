#include <stdio.h>
#include <stdlib.h>
/*
3. Existen dos reglas que identifican dos conjuntos de valores:

        A. El número es de un solo dígito.

        B. El número es impar.

    A partir de estas reglas, creá un algoritmo que contabilice en las variables estaEnA, estaEnB ,estaEnAmbos y noEstaEnNingunola
    condición según corresponda.Para indicar si el valor ingresado pertenece al primer conjunto,al segundo,
    a ambos o a ninguno, respectivamente. Definí un lote de prueba de varios números
    y probá el algoritmo, escribiendo los resultados tal como se hizo en los ejercicios anteriores.

  --------------------------------------------------------------------------------------
 |     PRUEBA ECHA CON TANDA DE 10 NUMERO , NUMERO USADOS : 4,5,6,7,8,9,10,11,12,13,14. |
 |     RESULTADO                                                                        |
 |      UnSoloDigito: 5                                                                 |
 |      EsImpar:      5                                                                 |
 |     EstaEnAmbosGrupos: 3                                                             |
 |      NoEstaEnNingunGrupo: 3                                                          |
  --------------------------------------------------------------------------------------
*/

int main()
{
    int number, flagOne, flagTwo, inA, inB, inTwoGroups, noneGroup, i;
    inA=0;
    inB= 0;
    inTwoGroups=0;
    noneGroup=0;

    for(i=0; i<10; i++)
    {
        flagOne=0;
        flagTwo=0;

        printf("Ingrese Numero: ");
        scanf("%d",&number);

        if(number>-10 && number<10)
        {
            inA++;
            flagOne=1;
        }
        if (!(number % 2==0))
        {
            inB++;
            flagTwo=1;
        }
        if(flagOne==1 && flagTwo==1)
        {
            inTwoGroups++;
        }
        if((flagOne==0 && flagTwo==0))
        {
            noneGroup++;
        }
    }
    printf("\n UnSoloDigito: %d \n EsImpar: %d\n EstaEnAmbosGrupos; %d \n NoEstaEnNingunGrupo: %d \n",inA,inB,inTwoGroups,noneGroup);
    return 0;
}
