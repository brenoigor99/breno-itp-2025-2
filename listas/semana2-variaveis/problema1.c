#include <stdio.h>

int main()
{
    // Declaração das variáveis para peso, altura e IMC
    float peso;
    float altura;
    float IMC;
    
    // Solicita ao usuário o peso em kg
    printf("Informe seu peso em kg: ");
    scanf("%f", &peso);
    
    // Solicita ao usuário a altura em metros
    printf("Informe sua altura em metros: ");
    scanf("%f", &altura);
    
    // Calcula o Índice de Massa Corporal (IMC = peso / altura²)
    IMC = peso / (altura*altura);

    // Exibe o resultado do IMC com duas casas decimais
    printf("Seu IMC é: %.2f", IMC);
    
    return 0;
}
