#include <stdio.h>

int main()
{
    float compra, desconto, valor_final;
    int porcentagem;
    
    printf("Digite o valor da compra em reais: \n");
    scanf("%f", &compra);

    /*Verifica se o valor é até R$ 100 (sem desconto)*/
    if(compra <= 100){
        desconto = 0;
        porcentagem = 0;
        valor_final = compra;
        printf("Sem desconto\n");
    }
    /*Aplica 10% de desconto para compras entre R$ 100,01 e R$ 500*/
    else if(compra > 100 && compra <= 500){
        desconto = compra * (0.10);
        porcentagem = 10;
        valor_final = compra - desconto;
    }
    /*Aplica 15% de desconto para compras entre R$ 500,01 e R$ 1000*/
    else if(compra > 500 && compra <= 1000){
        desconto = compra * (0.15);
        porcentagem = 15;
        valor_final = compra - desconto;
    }
    /*Aplica 20% de desconto para compras acima de R$ 1000*/
    else{
        desconto = compra * (0.20);
        porcentagem = 20;
        valor_final = compra - desconto;
    }
    /*Exibe o resumo da compra com todos os valores*/
    printf("Valor da compra: R$ %.2f\n", compra);
    printf("Desconto aplicado: %d%%\n", porcentagem);
    printf("Valor do desconto: R$ %.2f\n", desconto);
    printf("Valor final a pagar: R$ %.2f\n", valor_final);

    return 0;
}
