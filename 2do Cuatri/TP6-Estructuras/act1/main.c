/*
Desarrolle un programa que almacene datos de una canci�n en formato MP3: Artista,
T�tulo, Duraci�n (en segundos), Tama�o del fichero (en KB). Un programa debe pedir
los datos de una canci�n al usuario y despu�s mostrarlos en pantalla.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ====================    DECLARACI�N DE LA ESTRUCTURA DE ARTISTA        ==============================          */
typedef struct
{
    char nombre[15];
    char apellido[15];
} sArtista;

/* ====================    DECLARACI�N DE LA ESTRUCTURA DE CANCI�N  ==============================          */
typedef struct
{
    sArtista artista;
    char titulo[15];
    float duracion;

} sCancion;

void convertLowerCase(char bufferChar[]);
void  askForNameSong(char* mensaje,sCancion mp3);

// ----------------------------------------                    FUNCION MAIN                       --------  -------------------------------------------

int main()
{
    sCancion mp3 = { {"L-gante","Keloke"},"uno mas uno",150};
    askForNameSong("Ingrese titulo de la  cancion a buscar: ",mp3);
    return 0;
}

//-------------------------------------------------------------------------------------------------  -------------------------------------------

void convertLowerCase(char bufferChar[])
{
          for (int i=0; bufferChar[i]!= '\0'; i++)
         {
            bufferChar[i] = tolower(bufferChar[i]);
         }
}

void  askForNameSong(char* mensaje,sCancion mp3)
{
    char buscarCancion[25];
    printf("\n\n   -%s",mensaje);
    scanf("%[^\n]s",buscarCancion);
    convertLowerCase(buscarCancion);
    if(strcmp(buscarCancion,mp3.titulo)==0)
    {
        printf("\n Artista: %s %s \n Titulo: %s \n Durancion: %.fs \n\n ",mp3.artista.nombre, mp3.artista.apellido, mp3.titulo, mp3.duracion);
    } else
    {
        printf(" \n Titulo no encontrado \n");
    }
}

