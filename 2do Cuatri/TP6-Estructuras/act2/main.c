/******************************************************************************
Escriba un programa que lea datos de diez personas (nombre, edad, sexo, dirección, teléfono),
los almacene en una estructura y los muestre. Al realizar dicha muestra, destacar la persona más
joven en edad.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char calle[25];
    int numero;
    char localidad[25];

} sDireccion;

typedef struct
{
    char nombre[20];
    int edad;
    char sexo[0];
    sDireccion direccion[10];
    int telefono;

} sPersona;

void requestData(sPersona aPersonas[],int tam,int* positionYounger);
int askForChar(char* message, int tam,char aux[]);


//===============================                   FUNCION MAIN               ========================================

int main()
{
    int tam=10,positionYounger;
    sPersona aPersonas[tam];

    requestData(aPersonas,tam,&positionYounger);

    return 0;
}
//=================================================================================================

void requestData(sPersona aPersonas[],int tam,int* positionYounger)
{
    char auxName[15],auxSexo[0],auxCalle[30],auxAltura[5],auxLocalidad[30],auxTelefono[10],auxAge[4];
    int age,younger;
    for(int i=0 ; i<tam; i++)
    {
        if(    askForChar("\n Ingrese Nombre: ",tam,auxName)==1 &&
                askForChar("\n Ingrese Edad: ",tam,auxAge)==1 &&
                askForChar("\n Ingrese Sexo , F(Femenino) M(Masculino) : ",tam,auxSexo)==1 &&
                askForChar("\n Ingrese Calle: )",tam,auxCalle)==1 &&
                askForChar("\n Ingrese Altura: )",tam,auxAltura)==1 &&
                askForChar("\n Ingrese localidad: )",tam,auxLocalidad)==1 &&
                askForChar("\n Ingrese telefono: )",tam,auxTelefono)==1
          ){
                strcpy(aPersonas[i].nombre,auxName);
                age = atoi(auxAge);
                aPersonas[i].edad= age;
                strcpy(aPersonas[i].sexo,auxSexo);
                strcpy(aPersonas[i].direccion[i].calle,auxCalle);
                aPersonas[i].direccion[i].numero=atoi(auxAltura);
                strcpy(aPersonas[i].direccion[i].localidad,auxLocalidad);
                aPersonas[i].telefono=atoi(auxTelefono);

                if(i==0 || age<younger)
                {
                        *positionYounger = i;
                         younger=age;
                }

        }else{
            printf("\n Error en la carga, verificar...\n ");
        }
    }
}

int askForChar(char* message, int tam,char aux[])
{
    int retorno =0;

    if(message!=NULL && tam>0)
    {
        printf("%s",message);
        fflush(stdin);
        scanf("%[^\n]s",aux);

        retorno=1;
    }
    return retorno;
}

