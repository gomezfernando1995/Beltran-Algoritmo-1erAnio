#include <stdio.h>
#include <stdlib.h>
/*
    9. El club de corredores nos pide un programa para obtener estadísticas de la carrera de 10 km.
    El mismo consiste en ingresar, por teclado, el número de corredor, las horas, los minutos y los
     segundos que tardo en realizar la carrera. Tener en cuenta que al ingrear 0 como el número de
     corredor, finaliza el programa y debe mostrar por pantalla:
    El ganador
    El promedio en segundos de los corredores.
    El porcentaje de corredores que realizaron la carrera en menos de una hora.
*/
int main()
{
    int runner,i,winner;
    int hour,hourOld;
    int minute,minuteOld;
    int seconds,secondsOld,acumSeconds,averageSeconds;
    float fastestRunner;

    i=0;
    fastestRunner=0;
    runner=1;
    acumSeconds=0;
    averageSeconds=0;

    while(runner!=0)
    {
        printf("----------------------------------------------------");
        printf("\n Corredor: ");
        scanf("%d",&runner);
        while(runner<0)
        {
            printf(" Reingrese corredor: ");
            scanf("%d",&runner);
        }

        if(runner>0)
        {
            printf(" Hora: ");
            scanf("%d",&hour);
            while(hour<0)
            {
                printf(" Reingrese Hora: ");
                scanf("%d",&hour);
            }

            printf(" Minutos: ");
            scanf("%d",&minute);
            while(hour<0)
            {
                printf(" Reingrese Minutos: ");
                scanf("%d",&minute);
            }
            printf(" Segundos: ");
            scanf("%d",&seconds);

            while(hour<0)
            {
                printf(" Reingrese Segundos: ");
                scanf("%d",&seconds);
            }
            if(i==0 ||(hour<=hourOld && seconds<=secondsOld && minute<=minuteOld))
            {
                hourOld=hour;
                minuteOld=minute;
                secondsOld=seconds;
                winner=runner;
            }
            if(hour<1)
            {
                fastestRunner++;
            }
            acumSeconds+=seconds;
            i++;
        }
    }
    printf("---------------------------------------------------- ");
    if(i>0)
    {
        fastestRunner = (fastestRunner/i)*100;
        averageSeconds=acumSeconds/i;
        printf("\n Ganador: %d\n Promedio en segundos: %ds \n Carrera en menos de una hora: %.2f% \n",winner,averageSeconds,fastestRunner);
    }else{
        printf("\n No se ingresaron corredores \n");

    }
    return 0;
}
