#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



typedef struct
{
    char ciudad[30];
    char pais[30];
} sUbicacion;

typedef struct
{
    int dia;
    int mes;
    int anio;
    sUbicacion aUbicacion[3];
} sFecha;

typedef struct
{
    char nombre[30];
    float gastos;
    sUbicacion aUbicacion[3];
    sFecha aFechas[3];
} sProveedor;

int f_AskForChar(char* message, char aux[]);
int f_AskForInt(char* message,char* mensageError,int* aux,int min,int max);
int f_AskForFloat(char* message,char* mensageError,float* aux,int min,int max);
void mostrarLocalidades(int i);


int main()
{
    FILE* fichero;
    FILE* fichero2;
    fichero = fopen("proveedores-gastos.html","wt");
    fichero2=fopen("proveedores-gastos.csv","wt");
    int i,contDeGastos,tam=3;
    sProveedor aProveedores[tam];

        fputs("<table aling='center 'width='50%'  border='1'>", fichero);
        fputs("<tr><th>NOMBRE   <th><th>UBICACION  <th><th>GASTOS  <th><th>ULTIMO GASTO <th><th>GASTO TOTALES <th><tr>", fichero);
        for (i=0; i < tam; i++)
       {
        printf("\n --------------------------%d-------------------------------",i+1);
        f_AskForChar("\n  Ingrese el nombre del proveedor: ",aProveedores[i].nombre);
        f_AskForChar("  Ingrese el Pais del proveedor: ", aProveedores[i].aUbicacion[i].pais);
        if(i>0)
        {
            mostrarLocalidades(i);
        }
        f_AskForChar("  Ingrese  Localidad del proveedor: ", aProveedores[i].aUbicacion[i].ciudad);
        f_AskForFloat("  Ingrese el Gasto : "," Error, reingrese gasto: ",&aProveedores[i].gastos,0,1000000);
        printf("       \n       ----  Fecha de ultimo gasto ---- \n\n");
        f_AskForInt("   Ingrese el dia : "," Reingrese el dia: ",&aProveedores[i].aFechas[i].dia,1,31);
        f_AskForInt("   Ingrese el mes : "," Reingrese mes: ", &aProveedores[i].aFechas[i].mes,1,12);
        f_AskForInt("   Ingrese el anio : "," Reingrese anio: ",  &aProveedores[i].aFechas[i].anio,2000,2021);
        contDeGastos++;

        fprintf(fichero2,"%s; %.2f\n",aProveedores[i].nombre,aProveedores[i].gastos);
        fprintf(fichero, "<tr> <td >%-20s<td>    <td>%s,%s<td> <td>%d<td><td>%d/%d/%d<td><td>%.2f<td>    <tr>",aProveedores[i].nombre,aProveedores[i].aUbicacion[i].pais,aProveedores[i].aUbicacion[i].ciudad,contDeGastos
                ,aProveedores[i].aFechas[i].dia,aProveedores[i].aFechas[i].mes,aProveedores[i].aFechas[i].anio,aProveedores[i].gastos);
    }
        fputs("</table>", fichero);
        fclose(fichero2);

    return 0;
}

 void mostrarLocalidades(int i)
{
       FILE* fichero3;
        char localidades[10][20];
       fichero3=fopen("localidades.txt","rt");
       printf("\n     Localidades disponibles\n");
        for(int j=0; j<10; j++)
        {
          fscanf(fichero3, "%s" , localidades[i]);
          printf("     %d-%s\n", j+1,localidades[i]);
        }
       printf("\n");
}


/** \brief SOLICITAR/PEDIR UN DATO  CADENA DE TEXTO
 *
 * \param message ->  mensaje que se quiere mostrar por consola
 * \param aux-> puntero de la variable donde sera guardado la informacion ingresada
 * \return retorna 0 en caso  de que alguna variable sea NULL-- 1 si la carga finaliza con exito
 *
 */
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

/** \brief SOLICITAR/PEDIR UN DATO ENTERO
 *
 * \param message ->  mensaje que se quiere mostrar por consola
 * \param mensageError -> mensaje de error cuando el usuario ingresa el dato mal
 * \param aux-> puntero de la variable donde sera guardado la informacion ingresada
 * \param min-> valor minimo que puede tomar la variable ingresada
 * \param max-> valor minimo que puede tomar la variable ingresada
 * \return retorna 0 en caso  de que alguna variable sea NULL-- 1 si la carga finaliza con exito
 *
 */
int f_AskForInt(char* message,char* mensageError,int* aux,int min,int max)
{
    int retorno =0;

    if(message!=NULL)
    {
        printf("%s",message);
        scanf("%d",aux);
        while( *aux<min || *aux>max )
        {
            printf("\n %s",mensageError);
            scanf("%d",aux);
        }
        retorno=1;
    }
    return retorno;
}

int f_AskForFloat(char* message,char* mensageError,float* aux,int min,int max)
{
    int retorno =0;

    if(message!=NULL)
    {
        printf("%s",message);
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

