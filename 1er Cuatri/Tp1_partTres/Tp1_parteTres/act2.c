#include <stdio.h>
#include <stdlib.h>

/*Para entrar a la montaña rusa "Infierno en las alturas" nos piden tener al menos 7 años y medir más de 1,40m.
 Definí la operación necesaria y probala con los siguientes datos:


 */

int main()
{
    int age,height;

    printf("\n Ingrese edad: ");
    scanf("%d",&age);

    printf("\n Ingrese altura: ");
    scanf("%d",&height);

    if(age >= 7 && height>140)
    {
        printf("\n-     Bienvenido a la montaña rusa Infierno en las alturas     -\n");
    }
    else
    {
        printf("\n-     Lo siento no cumplis con las condiciones    -\n");
    }
    return 0;
}
