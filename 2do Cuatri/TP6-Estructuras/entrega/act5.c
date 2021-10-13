#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*  5.	Se debe gestionar los datos de stock de una tienda de comestibles, la información a recoger será: nombre del producto, precio, cantidad en stock.
            La tienda dispone de 10 productos distintos. El programa debe ser capaz de:
        	Dar de alta un producto nuevo.
        	Buscar un producto por su nombre.
        	Modificar el stock y precio de un producto dado.*/

typedef struct
{
    char nombreProducto[30];
    float precio;
    int stock;
    int isEmpty;

} sMercaderia;

///--------------------------------------------------------             Funciones           -----------------------------------------------------------------------
void  menuPrincipal(sMercaderia aMercaderia[],int tam);
int  mercaderia_isEmpty(sMercaderia array[],int tam);
int isEmpty(sMercaderia array[],int tam);
int  alta(sMercaderia aMercaderia[],int tam);
int buscar(sMercaderia aMercaderia[],int tam);
int modifcar(sMercaderia aMercaderia[],int tam);

int askForChar(char* message, char aux[]);
int askForInt(char* message,char* mensageError,int* aux,int min,int max);
int askForFloat(char* message,char* mensageError,float* aux,int min,int max);
//===============================                   FUNCION MAIN               ========================================

int main()
{
    int tam=10;
    sMercaderia aMercaderia[tam];
    isEmpty(aMercaderia,tam);

    menuPrincipal(aMercaderia,tam);
    return 0;
}

//====================================================================================================================================
void  menuPrincipal(sMercaderia aMercaderia[],int tam)
{
    int opcion;

    do{
        askForInt("  1-Alta\n  2-Buscar\n  3-Modificar\n  4-Salir\n\n   Elegir opcion: ", " Error, Opcion ingresada no existe",&opcion,1,4);
        system("cls");
        switch(opcion)
        {
        case 1:
            alta(aMercaderia,tam);
            break;
        case 2:
            buscar(aMercaderia,tam);
            break;
        case 3:
            modifcar(aMercaderia,tam);
            break;
        case 4:
                printf("\n\n -------------------- Tp hecho por Gomez Fernando (o_o) -------------------- \n\n");
           break;
        }
    }
    while(opcion!=4);
}
//======================================================            ALTA             ===============================================================
int alta(sMercaderia aMercaderia[],int tam)
{
    sMercaderia aux;
    int retorno=-1;
    int i;
    i= mercaderia_isEmpty(aMercaderia,tam);

    if(i==-1)
    {
        printf("\n          No es posible dar de alta por falta de espacio \n");
    }else{

        if(askForChar(" Ingrese nombre del producto: ", aux.nombreProducto)&&
                askForFloat(" Precio: "," Error, ingrese precio correcto : ",&aux.precio,0,1000000)&&
                askForInt(" Stock existente: "," Error, ingrese un stock correcto: ",&aux.stock,0,10000))
        {
            aMercaderia[i]=aux;
            aMercaderia[i].isEmpty=0;
            retorno=1;
            printf("\n Articulo: %s\n Precio:$%.2f\n Stock:%d \n",aMercaderia[i].nombreProducto,aMercaderia[i].precio,aMercaderia[i].stock);
            printf(" \n =============== Carga Exitosa del producto =============== \n");
        }else{
            printf("\n     Hubo un error en la carga \n");
        }
    }
    return retorno;
}

//=======================================================          BUSCAR                 ==================================================================
int buscar(sMercaderia aMercaderia[],int tam)
{
    char auxProducto[30];
    int i, posicionArticuloIgual,retorno=-1;

    askForChar(" Ingrese el articula que desea buscar: ",auxProducto);

    for(i=0; i<tam; i++)
    {
        if(strcmp(aMercaderia[i].nombreProducto,auxProducto)==0 && aMercaderia[i].isEmpty==0)
        {
            posicionArticuloIgual =i;
            printf("\n===============   Articulo Encontrado =============== \n");
            printf("\n Articulo: %s\n Precio:$%.2f\n Stock:%d \n",aMercaderia[posicionArticuloIgual].nombreProducto,aMercaderia[posicionArticuloIgual].precio,aMercaderia[posicionArticuloIgual].stock);
            printf("\n===================================================== \n");

            retorno=posicionArticuloIgual;
            break;
        }
    }
    if(retorno==-1){printf("\n===============   Articulo no encontrado =============== \n");}

    return retorno;
}

//======================================================          MODIFICAR      ====================================================================
int modifcar(sMercaderia aMercaderia[],int tam)
{
    system("cls");
    int auxModificar, posicionProducto=buscar(aMercaderia,tam),retorno = -1;

       if(posicionProducto!=-1)
       {
                askForInt(" 1-Modificar precio\n 2-Modificar Stock\n 3-Volver\n\n   Ingresar opcion: "," Error, Opcion ingresada no existe",&auxModificar,1,4);
                switch(auxModificar)
                {
                    case 1:
                            askForFloat(" Nuevo Precio: "," Error, Reingrese Precio",&aMercaderia[posicionProducto].precio,0,1000000);
                        break;
                    case 2:
                        askForInt(" Nuevo Stock: ","Error Reingrese stock: ",&aMercaderia[posicionProducto].stock,0,1000000);
                        break;
                }
                system("cls");
                printf("\n======== Articulo Modificado Correctamente  ======== \n");
                printf("\n Articulo: %s\n Precio:$%.2f\n Stock:%d \n",aMercaderia[posicionProducto].nombreProducto,aMercaderia[posicionProducto].precio,aMercaderia[posicionProducto].stock);
                printf("\n====================================================  \n");

                retorno = 1;
       }
       return retorno;
}

//====================================================================================================================================
//====================================================================================================================================

int askForChar(char* message, char aux[])
{
    int retorno =0;
    if(message!=NULL )
    {
        printf("\n%s",message);
        fflush(stdin);
        scanf("%[^\n]s",aux);

        for (int i=0; aux[i]!= '\0'; i++)
        {
            aux[i] = tolower(aux[i]);
        }
        aux[0] = toupper(aux[0]);
        retorno=1;
    }
    return retorno;
}

int askForInt(char* message,char* mensageError,int* aux,int min,int max)
{
    int retorno =0;

    if(message!=NULL)
    {
        printf("\n%s",message);
        scanf("%d",aux);
        while(*aux<min || *aux>max)
        {
            printf("\n %s",mensageError);
            scanf("%d",aux);
        }
        retorno=1;
    }
    return retorno;
}

int askForFloat(char* message,char* mensageError,float* aux,int min,int max)
{
    int retorno =0;

    if(message!=NULL)
    {
        printf("\n%s",message);
        scanf("%f",aux);
        while(*aux<min || *aux>max)
        {
            printf("\n %s",mensageError);
            scanf("%f",aux);
        }
        retorno=1;
    }
    return retorno;
}

int isEmpty(sMercaderia array[],int tam)
{
    int i;
    int result = -1;

    for(i=0; i<tam; i++)
    {
        array[i].isEmpty = 1;
        result = 0;
    }
    return result;
}

int  mercaderia_isEmpty(sMercaderia array[],int tam)
{
    int result = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if (array[i].isEmpty == 1)
        {
            result = i;
            break;
        }
    }
    return result;
}
