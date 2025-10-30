#include <stdio.h>

int main()
{
    int a, b, c, maior, lado1, lado2;

    printf("Digite o valor do a: ");
    scanf("%d", &a);

    printf("Digite o valor do b: ");
    scanf("%d", &b);

    printf("Digite o valor do c: ");
    scanf("%d", &c);

    // Verifica a desigualdade triangular (a soma de dois lados deve ser maior que o terceiro)
    if((a + b) < c || (a + c) < b || (b + c) < a){
        printf("Não é um triângulo\n");
        return 0;
    }
    // Classificação quanto aos lados
    printf("Classificação do triânculo:\n");

    // Equilátero: todos os lados iguais
    if(a == b && b == c){
        printf("Triângulo equilátero\n");
    }
    // Isósceles: dois lados iguais
    else if(a == b || a == c || b == c){
        printf("Triângulo isósceles\n");
    }
    // Escaleno: todos os lados diferentes
    else{
        printf("Triângulo escaleno\n");
    }

    // Classificação quanto aos ângulos
    printf("Classificação do ângulo:\n");
    
    // Identifica o maior lado (hipotenusa) e os outros dois lados
    if(a >= b && a >= c){
        maior = a;
        lado1 = b;
        lado2 = c;
    }
    else if(b >= a && b >= c){
        maior = b;
        lado1 = a;
        lado2 = c;
    }
    else{
        maior = c;
        lado1 = a;
        lado2 = b;
    }

    // Retângulo: maior² = lado1² + lado2² (ângulo de 90°)
    if((maior*maior) == ((lado1*lado1)+(lado2*lado2))){
        printf("Retângulo\n");
    }
    // Acutângulo: maior² < lado1² + lado2² (todos os ângulos menores que 90°)
    else if((maior*maior) < ((lado1*lado1) + (lado2*lado2))){
        printf("Acutângulo\n");
    }
    // Obtusângulo: maior² > lado1² + lado2² (um ângulo maior que 90°)
    else{
        printf("Obtusângulo\n");
    }

    return 0;
}
