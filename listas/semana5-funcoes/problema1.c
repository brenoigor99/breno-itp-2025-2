#include <stdio.h>

void escrever_horario(int horas, int minutos, int formato){

    // Normaliza minutos e horas para valores válidos
    while(minutos >= 60){
        minutos = minutos - 60;
        horas = horas + 1;
    }
    while(horas >= 24){
        horas = horas - 24;
    }
    // Formato 24h
    if(formato == 0){
        printf("%02d:%02d\n", horas, minutos);

    }
    // Formato 12h (AM/PM)
    else{
        if(horas == 0){
            printf("12:%02d AM\n", minutos);
        }
        else if(horas < 12){
            printf("%02d:%02d AM\n", horas, minutos);
        }
        else if (horas == 12){
            printf("12:%02d PM\n", minutos);
        }
        else{
            printf("%02d:%02d PM\n", horas - 12, minutos);
        }
    }
}

int main() 
{
    int h, m, formato;

    scanf("%d %d %d", &h, &m, &formato);
    
    // Exibe 5 horários diferentes com incrementos progressivos
    escrever_horario(h, m, formato);
    escrever_horario(h + 1, m + 0, formato);
    escrever_horario(h + 2, m + 10, formato);
    escrever_horario(h + 4, m + 40, formato);
    escrever_horario(h + 12, m + 5, formato);
    
    return 0;
}