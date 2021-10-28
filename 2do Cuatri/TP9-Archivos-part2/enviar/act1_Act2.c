#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*1.	Crea un programa que vaya leyendo las frases que el usuario teclea y las guarde
en un fichero de texto llamado “frases.txt”. Terminará cuando la frase introducida sea
"fin" (esa frase no deberá guardarse en el fichero). 
2-.	En base al primer punto, luego de generar la carga de las frases, visualizar el archivo cargado.
*/

int main()
{
    int flag=0;
    char frase[50],caracteres[500];
    FILE* txtFrases;

    do
    {
        printf("\n Ingrese Frase o fin para salir: ");
        fflush(stdin);
        scanf("%[^\n]s",frase);

        if(strcmp(frase,"fin")==0)
        {
                printf("\n Se finalizo la carga \n");
                flag=1;
        }
        else
       {
                if( (txtFrases=fopen("frases.txt","r") ) )
                {
                            txtFrases= fopen("frases.txt","at");
                            fprintf(txtFrases,"\n%s",frase);
                }else
                {
                        txtFrases= fopen("frases.txt","wt");
                        fprintf(txtFrases,"\n%s",frase);
                        printf("\n                       Primera carga exitosa \n");
                }
        }
     }while(flag!=1);
     fclose(txtFrases);

     //2.	En base al primer punto, luego de generar la carga de las frases, visualizar el archivo cargado.

     txtFrases=fopen("frases.txt","r");
     if(txtFrases ==NULL)
     {
            printf("\n      No existe el archivo\n");
     }else{
         while(feof(txtFrases)==0)
         {
              fgets(caracteres,500,txtFrases);
              printf("\n %s",caracteres);
         }
     }
       fclose(txtFrases);
     puts("\n");

    return 0;
}
