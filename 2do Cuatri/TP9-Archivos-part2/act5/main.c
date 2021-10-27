#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char ciudad[30];
    char pais[30];
} sUbicacion;

typedef struct
{
int dia:
    int mes;
int anio:
    sUbicacion aUbicacion[3];
} sFecha;

typedef struct
{
    char nombre[30];
    int gastos;
    sUbicacion aUbicacion[3];
    sFecha aFechas[3];
} sProveedor;


int main()
{
    FILE* fichero;
    fichero = fopen("proveedores-gastos.html","wt");
    sProveedor aProveedores[3];
    int i;
    fputs("<table>", fichero);
    fputs("<tr><td>Nombre</td><td>Apellido</td><td>Edad</td><td>Estatura</td></tr>", fichero);
    for (i=0; i < 2; i++)
    {

        printf(" Ingrese el nombre del proveedor: ");
        fflush(stdin);
        scanf("%[^\n]s", aProveedores[i].nombre);

        printf("Ingrese el Pais del proveedor: ");
        fflush(stdin);
        scanf("%[^\n]s", aProveedores[i].aUbicacion[i].pais);

        printf("Ingrese el Provincia del proveedor: ");
        fflush(stdin);
        scanf("%[^\n]s", aProveedores[i].aUbicacion[i].ciudad);

       printf("Ingrese el Gasto : ");
       scanf("%d", &aProveedores[i].gastos);

        printf("Ingrese el dia : ");
       scanf("%d", &aProveedores[i].aFechas.dia);
        printf("Ingrese el mes : ");
       scanf("%d", &aProveedores[i].aFechas.mes);
       printf("Ingrese el anio : ");
       scanf("%d", &aProveedores[i].aFechas.anio);


        fprintf(fichero, "<tr><td>%s</td><td>%s</td><td>%d</td><td>%d</td></tr> \n", cargaPersona[i].nombre, cargaPersona[i].apellido, cargaPersona[i].edad, cargaPersona[i].estatura);
    }

    fputs("</table>", fichero);



    printf("Hello world!\n");
    return 0;
}
