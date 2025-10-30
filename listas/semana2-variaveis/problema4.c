#include <stdio.h>

int main()
{
    // Declaração das variáveis para os dois números
    int a;
    int b;
    
    // Leitura dos valores informados pelo usuário
    printf("Informe o valor do a: ");
    scanf("%d", &a);
    
    printf("Informe o valor do b: ");
    scanf("%d", &b);
    
    // Calcula e exibe a soma dos dois números
    int soma;
    soma = a + b;
    printf("O valor da soma é: %d\n", soma);
    
    // Calcula e exibe a diferença (subtração)
    int diferença;
    diferença = a - b;
    printf("O valor da diferença é: %d\n", diferença);
    
    // Calcula e exibe o produto (multiplicação)
    int produto;
    produto = a * b;
    printf("O valor do produto é: %d\n", produto);
    
    // Calcula e exibe a divisão
    float divisao;
    divisao = (float)a / b; // Converte para float para obter resultado com decimais
    printf("O valor da divisão é: %f\n", divisao);
    
    // Calcula e exibe o resto da divisão (módulo)
    int resto;
    resto = a % b;
    printf("O valor do resto e: %d\n", resto);
    
    // Calcula e exibe a média aritmética
    float media;
    media = (float)(a + b)/2; // Converte para float para obter o resultado preciso
    printf("O valor da média é: %f", media);

    return 0;
}
