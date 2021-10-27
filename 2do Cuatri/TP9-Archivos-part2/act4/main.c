#include <stdio.h>
#include <stdlib.h>
/************************
4.	Crear un archivo denominado “enero.txt” que tenga 31 filas con el total de alumnos que
asistieron a un  Instituto. Leer dicho archivo y cargarlos dentro de un arreglo de valores.
Una vez cargado en el arreglo, mostrar desde allí los valores y la cantidad más alta y baja de asistencia.
*********************************************************************************/
 typedef struct {
        char nombre[50];
        int presentes;
    }sPersona;

int main()
{
    int fila=31,i,masPresente,menosPresente,iMasFaltador,iVaSiempre;
    sPersona aAlumnos[fila];
    FILE*   enero;

    enero = fopen("enero.txt","rt");

    for ( i = 0; i < fila; i++)
    {
        fscanf(enero, "%s %d" , aAlumnos[i].nombre,&aAlumnos[i].presentes);
        printf("    %-2d-%-9s %d \n", i+1,aAlumnos[i].nombre,aAlumnos[i].presentes);

        if(i==0 ||  menosPresente>aAlumnos[i].presentes)
        {
            menosPresente = aAlumnos[i].presentes;
            iMasFaltador =i;
        }
        if(i==0 || aAlumnos[i].presentes>masPresente)
        {
            masPresente =aAlumnos[i].presentes;
            iVaSiempre = i;
        }
    }
    fclose(enero);
    printf(" \n  Alumno menos presente: %s   Total: %d \n  Alumno con mas presentes: %s   Total: %d \n",aAlumnos[iMasFaltador].nombre,aAlumnos[iMasFaltador].presentes,aAlumnos[iVaSiempre].nombre,aAlumnos[iVaSiempre].presentes);

    return 0;
}
