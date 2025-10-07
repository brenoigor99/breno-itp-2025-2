#include <stdio.h>
#include <math.h>

int main()
{
    int A;
    printf("Informe o valor do A: \n");
    scanf("%d", &A);

    int B;
    printf("Informe o valor do B: \n");
    scanf("%d", &B);

    int soma_divisores_a = 0;
    int soma_divisores_b = 0;

    /*Calcula a soma dos divisores próprios de A (divisores menores que A)*/
    for(int i = 1; i < A; i++){
        if(A % i == 0){
            soma_divisores_a = soma_divisores_a + i;
        }
    }
    /*Calcula a soma dos divisores próprios de B (divisores menores que B)*/
    for(int i = 1; i < B; i++){
        if(B % i == 0){
            soma_divisores_b = soma_divisores_b + i;
        }
    }
    /*Armazena as somas em variáveis auxiliares*/
    int DA = soma_divisores_a;
    int DB = soma_divisores_b;

    /*Calcula a diferença entre a soma dos divisores de A e o valor de B*/
    int diferencial1 = DA - B;

    /*Calcula a diferença entre a soma dos divisores de B e o valor de A*/
    int diferencial2 = DB - A;

    /*Converte os diferenciais para valores absolutos (positivos)*/
    if(diferencial1 < 0){
        diferencial1 = -diferencial1;
    }
    if(diferencial2 < 0){
        diferencial2 = -diferencial2;
    }

    /*Verifica se A e B são números colegas, ou seja, a diferença é menor ou igual a 2 em ambas as direções*/
    if(diferencial1 <= 2 && diferencial2 <= 2){
        printf("S\n");
    }
    else{
        printf("N\n");
    }
    
    return 0;
}
