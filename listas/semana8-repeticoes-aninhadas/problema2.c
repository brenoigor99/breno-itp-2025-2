#include <stdio.h>
#include <string.h>

int main() 
{
    // Declara arrays para armazenar os meses, quantidades de chuva e variáveis auxiliares para troca
    char meses[12][20] = {
        "Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };
    char temp_mes[20];
    int chuvas[12];
    int temp_chuva;

    // Lê a quantidade de chuva para cada mês
    for(int i = 0; i < 12; i++){
        scanf("%d", &chuvas[i]);
    }
    // Ordena do maior para o menor com bubble sort
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11 - i; j++){
            if(chuvas[j] < chuvas[j + 1]){
                // Troca os valores de chuva
                temp_chuva = chuvas[j];
                chuvas[j] = chuvas[j + 1];
                chuvas[j + 1] = temp_chuva;
                // Troca os nomes dos meses
                strcpy(temp_mes, meses[j]);
                strcpy(meses[j], meses[j + 1]);
                strcpy(meses[j + 1], temp_mes);
            }
        }
    }
    // Escreve o ranking na tela
    for(int i = 0; i < 12; i++){
        printf("%s %d\n", meses[i], chuvas[i]);
    }
    
    return 0;
}