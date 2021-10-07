#include <stdio.h>
#include <stdlib.h>

fFechavalida()
{
    int result=1;

    if((dia<0 || dia>31 )|| (mes<1 || mes>12)||(año<1900 || año>2021))
    {
        result = 0;
    }
    return result;
}


void pedirDato(int* valor,char mensaje[])
{
    printf("%s",mensaje);
    scanf("%d",&valor);
}


int main()
{
    int dia,mes,año,Pdia,Pmes,pAño;

    pedirDato(&dia,"Ingrese dia: ");
    pedirDato(&mes,"Ingrese mes: ");
    pedirDato(&año,"Ingrese año: ");

    if(fFe)


    return 0;
}
