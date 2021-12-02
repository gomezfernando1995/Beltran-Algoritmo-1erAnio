#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 10

//                              GOMEZ FERNMANDO GABRIEL   DNI : 39387109

/*1.
  Utilizando estructuras, crear un programa que permita almacenar la siguiente información de productos. Anide estructuras según corresponda.
                    Valor
    Producto	Código	Compra	Venta	IVA	Stock	Marca
    SSD 160GB	9099121	$1500	$2100	21%	300	Samsung
2. Realice la carga de la información de diez productos por parte del usuario. Se deben contemplar las siguientes validaciones: (3p)
	2.1. Los valores de compra y venta deben encontrarse entre $1 y $50.000.
	2.2. El valor del IVA puede ser solo 21% o 10.5%
	2.3. El stock debe ser un valor superior o igual a 0. Sin tope.
    Para todas las validaciones, en caso de que no cumpla, se solicitará una y otra vez hasta que el valor sea correcto.
3.  Crear un procedimiento que visualice en pantalla la descripción del producto (y marca), el valor de venta
    (incrementado con su correspondiente IVA) y el stock restante. El procedimiento recibirá como parámetro el código
    del producto y deberá ser consultada al usuario luego de la carga para informar los resultados. Si no existe, deberá
    dar un mensaje en pantalla. (3p)
4. Generar una salida a un archivo CSV (separado por comas) con el siguiente contenido: Código, producto, marca y stock.
   Nombrar al archivo producto-stock.csv. Si el archivo existe, reemplazarlo. (1.5p)
5. Preguntar al usuario al finalizar si quiere visualizar en pantalla la información del archivo generado. Si responde que si, abrir y mostrar el contenido del archivo. (1.5p)

*/
typedef struct
{
    float compra;
    float venta;
    float iva;

} sValor;

typedef struct
{
    int codigo;
    char producto[25];
    sValor valorProducto[TAM];
    int stock;
    char marca [25];
} sProducto;

//**************    FUNCIONES     ******************************************************
int f_AskForChar(char* message, char aux[]);
int f_AskForInt(char* message,char* mensageError,int* aux,int min,int max);
int f_AskForFloat(char* message,char* mensageError,float* aux,int min,int max);
int esNumerica(char* cadena);
//**************************************************************************************

void pMostrarProducto(int codigo, int tam,sProducto arrayProductos[])
{
    int i;
    float ventaIVA=0;

    printf("\n  --------------------------------------------------------- ");
    for(i=0;i<tam;i++)
    {
        if(codigo == arrayProductos[i].codigo)
        {
            ventaIVA =arrayProductos[i].valorProducto[i].venta+(arrayProductos[i].valorProducto[i].venta*arrayProductos[i].valorProducto[i].iva)/100;
            printf("\n\n     Producto: %-10s Marca: %-10s Venta+IVA:%.2f\n",arrayProductos[i].producto,arrayProductos[i].marca,ventaIVA);
        }else{
                    printf("\n No se encontro el producto especificado ");
        }
    }
    printf("\n  --------------------------------------------------------- ");

}

void pCarga(FILE* archivo ,sProducto arrayProductos[],int tam)
{
    int i, codProducto;
    float auxIva;

    for(i=0; i<tam; i++)
    {
        printf("\n ------------------ Producto N%d ------------------",i+1);
        f_AskForInt("\n Codigo : ","     Error, reingrese codigo: ",&arrayProductos[i].codigo,0,10000000);
        f_AskForChar(" Producto: ",arrayProductos[i].producto);
        f_AskForChar(" Marca: ",arrayProductos[i].marca);
        f_AskForFloat(" Precio de compra: ","     Error, reingrese el valor de compra: ",&arrayProductos[i].valorProducto[i].compra,1,50000);
        f_AskForFloat(" Precio de venta: ","     Error, reingrese el valor de venta: ",&arrayProductos[i].valorProducto[i].venta,1,50000);
        printf(" IVA producto: ");
        scanf("%f",&auxIva);
        while(!(auxIva == 21 || auxIva ==10.5))
        {
            printf("     Error,Reingrese IVA producto: ");
            scanf("%f",&auxIva);
        }
        arrayProductos[i].valorProducto[i].iva = auxIva;
        f_AskForInt(" Stock: ","     Error, reingrese stock: ",&arrayProductos[i].stock,1,100000000);
        fprintf(archivo,"\n %d;%s;%s;%d",arrayProductos[i].codigo,arrayProductos[i].producto,arrayProductos[i].marca,arrayProductos[i].stock);
    }
      f_AskForInt("\n Ingrese Codigo del Producto para visualizar : ","     Error, reingrese codigo: ",&codProducto,0,10000000);
      pMostrarProducto(codProducto,tam,arrayProductos);
      fclose(archivo);
}

void pPreguntaMostrar(int tam)
{
    char caracteres[500],respuesta[4];
    FILE* fichero;

    f_AskForChar("\n\n Desea ver productos del archivo? si / no ...  ",respuesta);
    if(strcmp("Si",respuesta)==0)
    {
        fichero = fopen("producto-stock.csv","rt");
        if(fichero ==NULL)
         {
                printf("\n  No existe el archivo\n");
         }else{
             while(feof(fichero)==0)
            {
              fgets(caracteres,500,fichero);
              printf("\n %s",caracteres);
             }
         }
    }
}

/////////////////////////////////////////////////////         FUNCION MAIN            ///////////////////////////////////////////////////////////////

int main()
{
    int tam=TAM;
    sProducto arrayProductos[tam];
    FILE* fichero;

    fichero=fopen("producto-stock.csv","wt");
    pCarga(fichero,arrayProductos,tam);
    fclose(fichero);

    pPreguntaMostrar(tam);

    printf("\n\n\n          GRACIAS POR USAR EL SISTEMA  \n\n         Gomez Fernando Gabriel 1ro 1ra\n\n");
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int f_AskForChar(char* message, char aux[])
{
    int retorno =0;
    if(message!=NULL )
    {
        printf("%s",message);
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

int f_AskForInt(char* message,char* mensageError,int* aux,int min,int max)
{
    int retorno =0,num;
    char buffer[64];

    if(message!=NULL)
    {
         printf("%s",message);
         fflush(stdin);
         scanf("%[^\n]s",buffer);

         while(esNumerica(buffer)==0)
         {
            printf(" %s",mensageError);
            fflush(stdin);
            scanf("%[^\n]s",buffer);
         }
        num= atoi(buffer);
        while(num<min || num>max)
        {
            printf(" %s",mensageError);
            fflush(stdin);
            scanf("%d",&num);
        }
        *aux=num;
        retorno=1;
    }
    return retorno;
}


int f_AskForFloat(char* message,char* mensageError,float* aux,int min,int max)
{
    int retorno =0;
    float num;
    char buffer[64];

    if(message!=NULL)
    {
         printf("%s",message);
         fflush(stdin);
         scanf("%[^\n]s",buffer);

         while(esNumerica(buffer)==0)
         {
            printf(" %s",mensageError);
            fflush(stdin);
            scanf("%[^\n]s",buffer);
         }
        num= atof(buffer);
        while( num<min || num>max)
        {
            printf(" %s",mensageError);
            fflush(stdin);
            scanf("%f",&num);
        }
        *aux=num;
        retorno=1;
    }
    return retorno;
}

int esNumerica(char* cadena)
{
int retorno = 1;
int i=0;

	if(cadena[0]== '-')
	{
		i= 1;
	}
	for( ; cadena[i] != '\0';i++)
	{
		if(cadena[i] > '9' || cadena[i]<'0')
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}

