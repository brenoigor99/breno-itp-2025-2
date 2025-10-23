#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função que retorna apenas letras maiúsculas
int ehLetraMaiuscula(char c){
    return c >= 'A' && c <= 'Z';
}
// Função que retorna apenas algarismos (de 0 a 9)
int ehAlgarismo(char c){
    return c >= '0' && c <= '9';
}

int main()
{
    char placa[11];

    scanf("%s", placa);

    int tamanho = strlen(placa);
    // Verificação do padrão brasileiro: 8 caracteres (LLL-AAAA)
    if(tamanho == 8 &&
        ehLetraMaiuscula(placa[0]) &&
        ehLetraMaiuscula(placa[1]) &&
        ehLetraMaiuscula(placa[2]) &&
        placa[3] == '-' &&
        ehAlgarismo(placa[4]) &&
        ehAlgarismo(placa[5]) &&
        ehAlgarismo(placa[6]) &&
        ehAlgarismo(placa[7])){

        printf("brasileiro\n");
    }
    // Verificação do padrão mercosul: 7 caracteres (LLLALAA)
    else if(tamanho == 7 &&
        ehLetraMaiuscula(placa[0]) &&
        ehLetraMaiuscula(placa[1]) &&
        ehLetraMaiuscula(placa[2]) &&
        ehAlgarismo(placa[3]) &&
        ehLetraMaiuscula(placa[4]) &&
        ehAlgarismo(placa[5]) &&
        ehAlgarismo(placa[6])){

        printf("mercosul\n");
    }
    else{
        printf("inválido\n");
    }

    return 0;
}
