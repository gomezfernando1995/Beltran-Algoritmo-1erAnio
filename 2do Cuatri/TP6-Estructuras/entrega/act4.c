#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* 4.	Realice un programa que pida datos de 8 personas: nombre, día de nacimiento, mes de nacimiento, y año de nacimiento.
Después deberá repetir lo siguiente: preguntar un número de mes y mostrar en pantalla los datos de las personas que
cumplan los años durante ese mes. Terminará de repetirse cuando se teclee 0 como número de mes. */


typedef struct
{
    char nombre[30];
    int dia;
    int mes;
    int anio;
} sPersona;

///--------------------------------------------------------             Funciones          -----------------------------------------------------------------------
void requestData(sPersona aPersonas[],int tam);
int f_AskForInt(char* message,char* mensageError,int* aux,int min,int max);
int  checkRange(int* aux,int min, int max);
int askForChar(char* message, char aux[],int j);
void consultBirthday(sPersona aPersonas[],int tam);
//===============================                   FUNCION MAIN               ========================================

int main()
{
    int tam=8;
    sPersona aPersonas[tam];

    requestData(aPersonas,tam);
    system("cls");
    consultBirthday(aPersonas,tam);
    return 0;
}

//=================================================================================================


void requestData(sPersona aPersonas[],int tam)
{
    sPersona aux;
    int i;

    printf("\n ================ Carga y consulta de anios ================\n");
    for(i=0; i<tam; i++)
    {

        if(askForChar(" Ingrese nombre: ",aux.nombre,i) &&
                f_AskForInt("\n   Dia de nacimiento: ","Error, reingrese dia ",&aux.dia,1,31) &&
                f_AskForInt("   Mes de nacimiento: ","Error, reingrese mes ",&aux.mes,1,12) &&
                f_AskForInt("   Anio de nacimiento: ","Error, reingrese anio ",&aux.anio,1900,2022))
        {
            aPersonas[i]=aux;
            printf(" \n =============== Carga Exitosa =============== \n");
        }
        else
        {
            printf(" \n Hubo un error en la carga, verificar...\n");
        }
    }
}

void consultBirthday(sPersona aPersonas[],int tam)
{
    int aux,i,flag;
    do
    {
        f_AskForInt(" Ingrese el mes para ver sus cumpleanios o  '0' para salir: "," Error,reingrese el numero: ",&aux,0,12);
        flag=0;
        system("cls");
        printf( "\n ===============  PERSONAS QUE CUMPLEN ANIOS EL MES INDICADO   ============== \n");
        for(i=0; i<tam; i++)
        {
            if(aux == aPersonas[i].mes){
                printf("\n                  %-7s  - %-d/%-3d   - Este anio cumple: %d  ",aPersonas[i].nombre,aPersonas[i].dia,aPersonas[i].anio,(2021-aPersonas[i].anio));
                flag=1;
            }
        }
            if(flag==0){
                printf("\n             En el mes indicado nadie cumple anios .. \n");
            }
            printf( "\n ============================================================================ \n");

    }while(aux!=0);
}


int askForChar(char* message, char aux[],int j)
{
    int retorno =0;
    if(message!=NULL )
    {
        printf("\n%d-%s",j+1,message);
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
    int retorno =0;

    if(message!=NULL)
    {
        printf("%s",message);
        scanf("%d",aux);
        while( *aux<min || *aux>max)
        {
            printf("\n %s",mensageError);
            scanf("%d",aux);
        }
        retorno=1;
    }
    return retorno;
}
