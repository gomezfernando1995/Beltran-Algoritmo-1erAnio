#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Desarrolle un programa que almacene datos de una canción en formato MP3: Artista,
Título, Duración (en segundos), Tamaño del fichero (en KB). Un programa debe pedir
los datos de una canción al usuario y después mostrarlos en pantalla.  */

typedef struct
{
    char nombre[15];
    char apellido[15];
} sArtista;

typedef struct
{
    sArtista artista;
    char titulo[15];
    float duracion;

} sCancion;

void  askForNameSong(char* mensaje,sCancion mp3);
int askForChar(char* message, char aux[]);

// ----------------------------------------                    FUNCION MAIN                       --------  -------------------------------------------

int main()
{
    sCancion mp3 = { {"L-gante","Keloke"},"Uno mas uno",150};
    askForNameSong("Ingrese titulo de la  cancion a buscar: ",mp3);
    return 0;
}

//-------------------------------------------------------------------------------------------------  -------------------------------------------

void  askForNameSong(char* mensaje,sCancion mp3)
{
    char buscarCancion[25];

    askForChar(mensaje,buscarCancion);
    if(strcmp(buscarCancion,mp3.titulo)==0){
        printf("\n Artista: %s %s \n Titulo: %s \n Durancion: %.fs \n\n ",mp3.artista.nombre, mp3.artista.apellido, mp3.titulo, mp3.duracion);
    } else{
        printf(" \n Titulo no encontrado \n");
    }
}

int askForChar(char* message, char aux[])
{
    int retorno =0;
    if(message!=NULL )
    {
        printf("\n%s",message);
        fflush(stdin);
        scanf("%[^\n]s",aux);
        for (int i=0; aux[i]!= '\0'; i++){aux[i] = tolower(aux[i]);}
        aux[0] = toupper(aux[0]);
        retorno=1;
    }
    return retorno;
}
