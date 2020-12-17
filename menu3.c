#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include "fns/fadlkh.h"
#include "fns/alarma.h"

#define RANGO_MENU 4

char *menu[RANGO_MENU]={  "1- Hora\n",
                "2- Alarma\n",
                "3- Temporizador\n",
                "4- Salir\n"};
                
char *msgErrores[]={ "\nOpcion incorrecta\n"};
                    
int segundos;


void alarmaHandler(int sig){
    while(segundos > 0) {
        printf("%d", segundos);
        segundos = segundos - 1;
        alarm(1);
    }
}

int main()
{
    signal(SIGALRM, alarmaHandler);
    int pulsado;
    int hora;
    int minuto;
    time_t tiempo;
    struct tm * infotiempo;
    while (1){
        ver_menu(RANGO_MENU,menu);//atentos a la llamada
        pulsado=leerOpcion();
        if (pulsado<1 || pulsado>RANGO_MENU){
            printf("Error: %s",msgErrores[0]);
        }
        else {
            switch (pulsado)
            {
                case 1:
                    while(1){
                        system("clear");
                        time(&tiempo);
                        printf("\n\n\n\t\t%s", ctime(&tiempo));
                        fflush(stdout);
                        sleep(1);
                    }
                    break;
                case 2:
                    printf("Introduce la hora deseada para la alarma [HH:MM] \n");
                    scanf("%d:%d", &hora, &minuto);
                    time(&tiempo);
                    infotiempo = localtime(&tiempo);
                    segundos = (hora - infotiempo->tm_hour)*3600 +
                        (minuto - infotiempo->tm_min)*60;
                    printf("%d",segundos);
                    break;
                case 3:
                    printf("Introduce los segundos para el temporizador \n");
                    scanf("%d", &segundos);
                    for (segundos; segundos > 0; --segundos){
                        system("clear");
                        printf("segundos: %d", segundos);
                        fflush(stdout);
                        sleep(1);
                    }
                    break;
                case 4:
                    exit(-1);
            }
        }
    }
    return 0;
}



