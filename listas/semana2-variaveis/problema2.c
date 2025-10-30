#include <stdio.h>

int main()
{
    // Declaração das variáveis para as temperaturas
    float Celsius;
    float Fahrenheit;
    float Kelvin;
    
    // Solicita ao usuário a temperatura em graus Celsius
    printf("informe a temperatura em graus celsius: ");
    scanf("%f", &Celsius);
    
    // Converte Celsius para Fahrenheit usando a fórmula: F = (C × 9/5) + 32
    Fahrenheit = (Celsius * 9/5) + 32;

    // Converte Celsius para Kelvin usando a fórmula: K = C + 273.15
    Kelvin = Celsius + 273.15;
    
    // Exibe os resultados das conversões
    printf("A conversão de Celsius para Fahrenheit é: %.1f\n", Fahrenheit); // Printa a conversão em Fahrenheit
    printf("A conversão de Celsius para Kelvin é: %1.f", Kelvin); // Printa a conversão em Kelvin
    
    return 0;
}
