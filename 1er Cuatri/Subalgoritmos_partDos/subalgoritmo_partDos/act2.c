#include <stdio.h>
#include <stdlib.h>
/*
    El programa debe visualizar una nota numérica equivalente con en el Standard Grading System (sistema utilizado en los Estados Unidos
    que va desde la A hasta la F). Realícelo mediante un procedimiento:
    9.0 - 10.0: A
    8.5 - 8.9: B+
    8.0 - 8.4: B
    7.5 - 7.9: C+
    7.0 - 7.4: C
    6.0 - 6.9: D
    0.0 - 6.0: F
*/

void notasSGS(float nota)
{
    if(nota>=9 && nota<=10){
        printf("\n A\n");
    }else if(nota>=8.5) {
        printf("\n B+\n");
    }else if(nota>=8) {
        printf("\n B\n");
    }else if(nota>=7.5) {
        printf("\n C+\n");
    }else if(nota>=7) {
        printf("\n C\n");
    }else if(nota>=6){
        printf("\n D\n");
    }else {
        printf("\n F\n");
    }
}

int main()
{
    float nota;

    printf("\n Ingrese nota: ");
    scanf("%f",&nota);
    while(nota<0 || nota>10)
    {
        printf("\n Reingrese nota: \n");
        scanf("%f",&nota);
    }
    notasSGS(nota);
    return 0;
}
