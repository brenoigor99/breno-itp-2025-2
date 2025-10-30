#include <stdio.h>

int main()
{
    float peso;
    printf("Digite seu peso em kg: \n");
    scanf("%f", &peso);

    float altura;
    printf("Digite a sua altura em metros: \n");
    scanf("%f", &altura);

    // Declaração da variável IMC e cálculo do Índice de Massa Corporal
    int IMC;
    IMC = peso / (altura*altura); // Fórmula: peso / altura²

    /*Cria uma conficional, no qual se o IMC for menor do que 18.5, irá dar output: "Abaixo do peso",
    caso o IMC fique entre 18.5 e 24.9, então irá dar output: "Peso normal", se estiver entre
    25 e 29.9, irá printar: "Sobrepeso" e se estiver acima, então pritará: "Obesidade".*/
    if(IMC < 18.5){
        printf("Abaixo do peso \n");
    }
    else if(IMC >= 18.5 && IMC <= 24.9){
        printf("Peso normal \n");
    }
    else if(IMC >= 25 && IMC <= 29.9){
        printf("Sobrepeso \n");
    }
    else{
        printf("Obesidade");
    }

    return 0;
}
