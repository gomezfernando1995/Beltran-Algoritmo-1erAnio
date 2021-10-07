#include <stdio.h>
#include <stdlib.h>
/*
3. Determinar si una persona es mayor o menor de acuerdo a su edad. Mayoría de edad a partir de los 21 años.
*/
int main()
{
   int edad;

   printf("\nIngrese edad: ");
   scanf("%d",&edad);
   while(!(edad>0 && edad<100))
   {
      printf("\nReingrese edad: ");
      scanf("%d",&edad);
   }

   if(edad>21)
   {
        printf("\nUsted es mayor de  21 años\n");
   }else
   {
        printf("\nUsted es menor de 21 años\n");
   }
    return 0;
}
