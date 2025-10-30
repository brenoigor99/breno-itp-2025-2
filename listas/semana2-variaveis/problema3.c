#include <stdio.h>
#include <math.h> // Biblioteca necessária para a função pow()

int main()
{
    // Declaração das variáveis para cálculo de juros compostos
    float capital;
    float taxa;
    float tempo;
    float montante;
    
    // Solicita o valor do capital inicial
    printf("Digite seu capital: ");
    scanf("%f", &capital);
    
    // Solicita a taxa de juros em porcentagem
    printf("Digite o valor dos juros em porcentagem: ");
    scanf("%f", &taxa);
    
    // Solicita o tempo de aplicação em anos
    printf("Digite o tempo em anos: ");
    scanf("%f", &tempo);
    
    // Calcula o montante usando a fórmula de juros compostos: M = C × (1 + taxa/100)^t
    montante = capital * pow(1 + taxa/100, tempo);
    
    // Exibe o montante final
    printf("O montante final é: %f", montante);
    
    return 0;
}
