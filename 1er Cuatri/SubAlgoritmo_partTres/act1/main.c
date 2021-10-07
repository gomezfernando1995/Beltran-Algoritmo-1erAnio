#include <stdio.h>

int fCantidadSegundos (int horas, int minutos, int segundos)
{
    return ((horas * 3600) + (minutos * 60) + segundos);
}

int main ()
{
    int horas = 0, minutos = 10, segundos = 10;
    int resultado;
    resultado = fCantidadSegundos(horas, minutos, segundos);
    printf ("Cantidad de segundos totales %d:%d:%d -> %d", horas, minutos, segundos, resultado);
}
