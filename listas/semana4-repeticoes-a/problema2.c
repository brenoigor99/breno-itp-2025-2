#include <stdio.h>
#include <math.h>

int main()
{
    float x, y;
    printf("Informe a coordenada inicial do homem-aranha: \n");
    scanf("%f %f",&x, &y);

    float comprimento_max;
    printf("Informe o comprimento máximo da teia: \n");
    scanf("%f", &comprimento_max);

    int n;
    printf("Informe a quantidade de alvos: \n");
    scanf("%d", &n);

    float ax, ay;
    float distancia;

    for(int i = 0; i < n; i++){
        printf("Informe as coordenadas do alvo: \n");
        scanf("%f %f", &ax, &ay);
        
        // Calcula a distância euclidiana entre a posição atual e o alvo
        distancia = sqrt((ax - x) * (ax - x) + (ay - y) * (ay - y));

        if(distancia <= comprimento_max){
            // Atualiza a posição do Homem-Aranha (balança até o alvo e continua na mesma direção)
            x = 2*ax - x;
            y = y;
        }  
        else{
            // Se algum alvo está fora do alcance, então não é possível completar a sequência
            printf("N\n");
            return 0;
        }
    }
    
    printf("S\n");

    return 0;
}
