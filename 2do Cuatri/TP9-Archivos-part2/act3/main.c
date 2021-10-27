#include <stdio.h>
#include <stdlib.h>
/*************************************************************************************************************
3.	Crear un archivo que se llame “montos.txt”, en el mismo se almacenarán
valores numéricos. Realizar un proceso que visualice su contenido y, al finalizar,
 muestre el total (sumatoria de los valores) y promedio.

 *************************************************************************************************************/

void mostrar(char archivo[])
{
    char caracteres[500];
    FILE* fichero;

    fichero = fopen(archivo,"r");
    if(fichero == NULL)
    {
        puts("El archivo no existe\n");
    }else{
        while(feof(fichero)==0)
        {
               fgets(caracteres,500,fichero);
               printf("\n %s",caracteres);
        }
    }
    fclose(fichero);
}

int main()
{
    int numero,total=0,i=0;
    float promedio=0;
    FILE* montos;

      montos=fopen("montos.txt","wt");
      fclose(montos);
    do{
            printf("\n Numero [salir 0] : ");
            scanf("%d",&numero);

            if(numero !=0)
            {
                  i++;
                total+=numero;
                promedio = total/i;

                montos= fopen("montos.txt","at");
                fprintf(montos,"\n Numero : %-5d ....Total: %-5d... Promedio: %.1f",numero,total,promedio);

             fclose(montos);
            }
    }while(numero !=0);

    mostrar("montos.txt");
    puts(" ");
    return 0;
}
