#include <stdio.h>
#include <stdlib.h>

/*
    Escribir un programa que retorne el signo zodiacal de una persona.
    Para ello el usuario debe introducir únicamente el día y el mes de nacimiento y
    mediante un subprograma determinará inmediatamente el signo zodiacal de la persona.
    Realícelo mediante un procedimiento.
*/

void pSignoZodiacal(int dia, int mes)
{
        printf("\n---------------------------------------------");
    switch(mes)
    {
        case 1:
            if(dia<19)
            {
                printf("\n Sagitario\n");
            }else{
                printf("\n Capricornio\n");
            }
        break;
        case 2:
            if(dia<16)
            {
                printf("\n Capricornio\n");
            }else if(dia<29){
                printf("\n Acuario\n");
            }else{
                printf("\n Error, febrero solamente tiene 28 dias\n");
            }
        break;
        case 3:
            if(dia<12)
            {
                printf("\n Acuario\n");
            }else{
                printf("\n Piscis\n");
            }
        break;
        case 4:
            if(dia<19)
            {
                printf("\n Piscis\n");
            }else if(dia<31){
                printf("\n Aries\n");
            }else {
                printf("\n Error, abril solamente tiene 30 dias\n");
            }
        break;
        case 5:
            if(dia<14)
            {
                printf("\n Aries\n");
            }else{
                printf("\n Tauro\n");
            }
        break;
        case 6:
            if(dia<20)
            {
                printf("\n Tauro\n");
            }else if(dia<31){
                printf("\n Géminis\n");
            }else {
                printf("\n Error, junio solamente tiene 30 dias\n");
            }
        break;
        case 7:
            if(dia<21)
            {
                printf("\n Géminis\n");
            }else if(dia<31){
                printf("\n Cáncer\n");
            }else {
                printf("\n Error, julio solamente tiene 30 dias\n");
            }
        break;
        case 8:
            if(dia<10)
            {
                printf("\n Cáncer\n");
            }else{
                printf("\n Leo\n");
            }
        break;
        case 9:
            if(dia<16)
            {
                printf("\n Leo\n");
            }else if(dia<31){
                printf("\n Virgo\n");
            }else {
                printf("\n Error, septiembre solamente tiene 30 dias\n");
            }
        break;
        case 10:
            if(dia<31)
            {
                printf("\n Cáncer\n");
            }else{
                printf("\n Libra\n");
            }
        break;
        case 11:
            if(dia<23) {
                printf("\n Libra\n");
            }else if(dia<30){
                printf("\n Virgo\n");
            }else if(dia<31)
            {
                printf("\n Ofiuco\n");
            }else{
                printf("\n Error, noviembre solamente tiene 30 dias\n");
            }
        break;
        case 12:
            if(dia<18)
            {
                printf("\n Ofiuco \n");
            }else{
                printf("\n Sagitario \n");
            }
        break;
    }
        printf("---------------------------------------------");

}

int main()
{
    int dia,mes;

    printf("\n Ingrese dia: ");
    scanf("%d",&dia);
    while(dia<1 || dia>31)
    {
         printf("\n Error, reingrese dia: ");
         scanf("%d",&dia);
    }
    printf("\n 1-Enero\n 2-Febrero\n 3-Marzo\n 4-Abril\n 5-Mayo\n 6-Junio\n 7-Julio\n 8-Agosto\n 9-Septiembre\n 10-Octubre\n 11-Noviembre\n 12-Diciembre\n\n Ingrese mes: ");
    scanf("%d",&mes);
    while(mes<1 || mes>31)
    {
         printf("\n Error, reingrese mes: ");
         scanf("%d",&mes);
    }

    pSignoZodiacal(dia,mes);
    printf("\n\n ¿Por qué no aparece Ofiuco como constelación zodiacal en el horóscopo?"
           "¿Por qué no coinciden las fechas? No lo hacen porque hace 2.500 años, cuando se originó el horóscopo en "
           "la antigua Babilonia, el Sol pasaba en fechas diferentes por cada una de las constelaciones zodiacales"
           "aproximadamente cuatro semanas antes.\n\n");

    return 0;
}






