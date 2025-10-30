#include <stdio.h>
#include <math.h>

// Calcula altura do terreno usando função trigonométrica
float calcular_altura(float x, float y){

    return sin(cos(y) + x) + cos(y + sin(x));
}
// Verifica se um ponto é seguro checando a altura no ponto e em 4 pontos ao redor (diagonal com distância 0.2)
int eh_ponto_seguro(float x, float y){
    float altura;

    altura = calcular_altura(x, y);
    if(altura < 0.0 || altura > 2.0){
        return 0;
    }

    altura = calcular_altura(x + 0.2, y + 0.2);
    if(altura < 0.0 || altura > 2.0){
        return 0;
    }

    altura = calcular_altura(x - 0.2, y - 0.2);
    if(altura < 0.0 || altura > 2.0){
        return 0;
    }
 
    altura = calcular_altura(x + 0.2, y - 0.2);
    if(altura < 0.0 || altura > 2.0){
        return 0;
    }

    altura = calcular_altura(x - 0.2, y + 0.2);
    if(altura < 0.0 || altura > 2.0){
        return 0;
    }
    
    return 1; // Todas as verificações passaram, logo, o ponto é seguro
}

int main() {
    float x, y;
    int pontos_seguros;

    scanf("%f %f", &x, &y);
    
    if(!eh_ponto_seguro(x, y)){
        printf("troque de coordenada\n");
        return 0;
    }
    // Conta quantos dos 4 pontos adjacentes (distância 2) são seguros
    pontos_seguros = 0;
    
    if(eh_ponto_seguro(x + 2, y)){
        pontos_seguros++;
    }
    
    if(eh_ponto_seguro(x - 2, y)){
        pontos_seguros++;
    }
    
    if(eh_ponto_seguro(x, y - 2)){
        pontos_seguros++;
    }
    
    if(eh_ponto_seguro(x, y + 2)){
        pontos_seguros++;
    }
    // Classifica o nível de segurança baseado na quantidade de pontos seguros ao redor
    if(pontos_seguros == 0 || pontos_seguros == 1){
        printf("inseguro\n");
    }
    else if(pontos_seguros == 2 || pontos_seguros == 3){
        printf("relativamente seguro\n");
    }
    else{
        printf("seguro\n");
    }
    
    return 0;
}