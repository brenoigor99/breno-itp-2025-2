#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, delta, raizP, raizN;

    // Leitura dos coeficientes da equação de segundo grau
    printf("Digite o valor do a: ");
    scanf("%lf", &a);

    printf("Digite o valor do b: ");
    scanf("%lf", &b);

    printf("Digite o valor do c: ");
    scanf("%lf", &c);

    // Verifica se 'a' é diferente de zero (condição para equação do segundo grau)
    if(a == 0){
        printf("Não é uma equação do segundo grau\n");
        return 0;
    }

    // Calcula o delta da equação (delta = b² - 4ac)
    delta = b*b - 4*a*c;

    // Delta positivo: duas raízes reais e distintas
    if(delta > 0){
        raizP = (-b + sqrt(delta))/(2*a); // Fórmula de Bhaskara: x1 = (-b + raiz(delta)) / 2a
        raizN = (-b - sqrt(delta))/(2*a); // Fórmula de Bhaskara: x2 = (-b - raiz(delta)) / 2a
        printf("Possui duas raízes reais distintas:\n");
        printf("X1 = %.2lf\n", raizP);
        printf("X2 = %.2lf", raizN);
    }
    // Delta igual a zero: uma raiz real (raízes iguais)
    else if(delta == 0){
        raizP = -b /(2*a);
        printf("Possui uma raiz real:\n");
        printf("X = %.2lf", raizP);
    }
    // Delta negativo: não possui raízes reais
    else{
        printf("Não possui raízes reais\n");
    }

    return 0;
}
