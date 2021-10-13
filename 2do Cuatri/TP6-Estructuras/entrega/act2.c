
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/******************************************************************************
Escriba un programa que lea datos de diez personas (nombre, edad, sexo, dirección, teléfono),
los almacene en una estructura y los muestre. Al realizar dicha muestra, destacar la persona más
joven en edad.

*******************************************************************************/
typedef struct
{
    char calle[25];
    float numero;
    char localidad[25];
} sDireccion;

typedef struct
{
    char nombre[20];
    float edad;
    char sexo[3];
    sDireccion direccion[10];
    float telefono;
} sPersona;

///--------------------------------------------------------             Funciones      -----------------------------------------------------------------------
void requestData(sPersona aPersonas[],int tam,int* positionYounger);
int askForChar(char* message, int tam,char aux[]);
int askForFloat(char* message, int tam,float* aux);
void showData(sPersona aPersonas[],int positionYounger);

//===============================                   FUNCION MAIN               =============================

int main()
{
    int tam=10,positionYounger;
    sPersona aPersonas[tam];

    requestData(aPersonas,tam,&positionYounger);
    showData(aPersonas,positionYounger);

    return 0;
}

//======================================= PEDIR DATOS ====================================

void requestData(sPersona aPersonas[],int tam,int* positionYounger)
{
    sPersona sAuxPersona;
    int younger;
    for(int i=0 ; i<tam; i++)
    {
        if(    askForChar("\n   Ingrese Nombre: ",tam,sAuxPersona.nombre)==0 &&
                askForFloat("\n  Ingrese Edad: ",tam,&sAuxPersona.edad)==1 &&
                askForChar("\n  Ingrese Sexo , F(Femenino) M(Masculino) : ",tam,sAuxPersona.sexo)==1 &&
                askForChar("\n  Ingrese Calle: ",tam,sAuxPersona.direccion->calle)==1 &&
                askForFloat("\n  Ingrese Altura: ",tam,&sAuxPersona.direccion->numero)==1 &&
                askForChar("\n  Ingrese localidad: ",tam,sAuxPersona.direccion->localidad)==1 &&
                askForFloat("\n  Ingrese telefono: ",tam,&sAuxPersona.telefono)==1
          ){
                aPersonas[i]=sAuxPersona;
                strcpy(aPersonas[i].direccion[i].calle, sAuxPersona.direccion->calle);
                aPersonas[i].direccion[i].numero= sAuxPersona.direccion->numero;
                strcpy(aPersonas[i].direccion[i].localidad, sAuxPersona.direccion->localidad);

                printf(" \n\n ---------------------------------| Datos Cargados Correctamente  |--------------------------------- \n");
                if(i==0 || sAuxPersona.edad<younger)
                {
                        *positionYounger = i;
                         younger=sAuxPersona.edad;
                }
        }else{
            printf("\n Error en la carga, verificar...\n ");
        }
    }
}
//======================================= MOSTRAR DATOS  ==================================

void showData(sPersona aPersonas[],int positionYounger)
{
       printf("\n  #### Persona Mas Joven #### \n\n  -Nombre: %s\n  -Edad: %.f\n  -Sexo: %s\n  -Direccion: %s %.f, %s \n  -Tel: %.f \n\n",aPersonas[positionYounger].nombre,aPersonas[positionYounger].edad,aPersonas[positionYounger].sexo,
                    aPersonas[positionYounger].direccion[positionYounger].calle,aPersonas[positionYounger].direccion[positionYounger].numero,aPersonas[positionYounger].direccion[positionYounger].localidad, aPersonas[positionYounger].telefono);
}
//======================================= ===============================================

int askForChar(char* message, int tam,char aux[])
{
    int retorno =0;
    if(message!=NULL && tam>0)
    {
        printf("%s",message);
        fflush(stdin);
        scanf("%[^\n]s",aux);
        for (int i=0; aux[i]!= '\0'; i++){aux[i] = tolower(aux[i]);}
            aux[0] = toupper(aux[0]);
        retorno=1;
    }
    return retorno;
}
//======================================= ===============================================

int askForFloat(char* message, int tam,float* aux)
{
    int retorno =0;

    if(message!=NULL && tam>0)
    {
        printf("%s",message);
        fflush(stdin);
        scanf("%f",aux);
        retorno=1;
    }
    return retorno;
}
