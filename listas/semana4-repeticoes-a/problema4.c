#include <stdio.h>
#include <math.h>

int main()
{
    float x;
    float y;
    float x_anterior, y_anterior;
    float distancia_centro;
    float distancia_anterior;

    int pontuacao_total = 0;
    int pontuacao_principal;
    int pontuacao_bonus;

    printf("Digite as coordenadas (x, y) de 10 lançamentos: \n");

    for(int i = 0; i < 10; i++){
        printf("Lançamentos %d: ", i + 1);
        scanf("%f %f", &x, &y);

        /*calcula distância euclidiana do ponto até a origem*/
        distancia_centro = sqrt((x*x) + (y*y));

        /*pontuação baseada na distância ao centro*/
        if(distancia_centro <= 1.0){
            pontuacao_principal = 10;
        }
        else if(distancia_centro <= 2.0){
            pontuacao_principal = 6;
        }
        else if(distancia_centro <= 3.0){
            pontuacao_principal = 4;
        }
        else{
            pontuacao_principal = 0;
        }

        pontuacao_total = pontuacao_total + pontuacao_principal;

        /*Calcula pontuação bônus a partir do segundo lançamento*/
        if(i > 0){
            /*Calcula a distância entre o lançamento atual e o anterior*/
            distancia_anterior = sqrt((x - x_anterior) * (x - x_anterior) + (y - y_anterior) * (y - y_anterior));
            /*Determina a pontuação bônus baseada na proximidade com o lançamento anterior*/
            if(distancia_anterior <= 1.0){
                pontuacao_bonus = 5;
            }
            else if(distancia_anterior <= 2){
                pontuacao_bonus = 3;
            }
            else if(distancia_anterior <= 3){
                pontuacao_bonus = 2;
            }
            else{
                pontuacao_bonus = 0;
            }
            pontuacao_total = pontuacao_total + pontuacao_bonus;

            printf("Distância ao centro: %.2f (pontuação principal: %d)\n", distancia_centro, pontuacao_principal);
            printf("Distância anterior: %.2f (pontuação bônus: %d)\n", distancia_anterior, pontuacao_bonus);
        }
        else{
            printf("Distância ao centro: %.2f (pontuação principal: %d)\n", distancia_centro, pontuacao_principal);
            printf("Primeiro lançamento - sem pontos\n");
        }

        /*Armazena as coordenadas atuais para uso na próxima iteração*/
        x_anterior = x;
        y_anterior = y;
    }

    printf("Pontuação total: %d pontos\n", pontuacao_total);

    return 0;
}
