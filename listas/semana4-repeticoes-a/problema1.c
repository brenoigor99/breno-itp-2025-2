#include<stdio.h>

int main()
{
    float comprimento;
    printf("Digite o comprimento da folha: \n");
    scanf("%f", &comprimento);
    
    float largura;
    printf("Digite a largura da folha: \n");
    scanf("%f", &largura);

    float comprimento_bolso;
    printf("Digite o comprimento do bolso: \n");
    scanf("%f", &comprimento_bolso);
    
    // Determina qual é o menor lado da folha
    float menor_lado;
    
    if(comprimento  <= largura){
        menor_lado = comprimento;
    }
    else{
        menor_lado = largura;
    }

    int dobras = 0;
    
    // Continua dobrando até que o menor lado caiba no bolso
    while(menor_lado > comprimento_bolso){
        // Dobra sempre o maior lado pela metade
        if(comprimento >= largura){
            comprimento = comprimento/2;
        }
        else if(comprimento < largura){
            largura = largura/2;
        }
        // Atualiza qual é o menor lado após a dobra
        if(comprimento  <= largura){
            menor_lado = comprimento;
        }
        else{
            menor_lado = largura;
        }
        dobras++;
    }
    
    printf("%d dobras", dobras);

    return 0;
}
