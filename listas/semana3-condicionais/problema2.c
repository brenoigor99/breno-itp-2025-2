#include <stdio.h>

int main()
{
    char cobranca = ' ';
    printf("Digite onde será feita a cobrança (Residencial (R), comercial (C) ou industrial (I)): \n");
    scanf(" %c", &cobranca);

    float consumo, valor_conta, valor_total_conta;

    // Verifica se a opção digitada é válida antes de solicitar o consumo
    if(cobranca == 'R' || cobranca == 'C' || cobranca == 'I'){
    printf("Digite o consumo da energia em kWh: \n");
    scanf("%f", &consumo);
    }
    // Calcula o valor para cobrança residencial (R$ 0,60 por kWh + taxa de R$ 15)
    if(cobranca == 'R'){
        valor_conta = consumo * (0.60); 
        valor_total_conta = valor_conta + 15; 
        printf("O valor total da conta residencial é: %.2f reais\n", valor_total_conta);
    }
    // Calcula o valor para cobrança comercial (R$ 0,48 por kWh + taxa de R$ 15)
    else if(cobranca == 'C'){
        valor_conta = consumo * (0.48);
        valor_total_conta = valor_conta + 15; 
        printf("O valor total da conta comercial é: %.2f reais\n", valor_total_conta);
    }
    // Calcula o valor para cobrança industrial (R$ 1,29 por kWh + taxa de R$ 15)
    else if(cobranca == 'I'){
        valor_conta = consumo * (1.29);
        valor_total_conta = valor_conta + 15; 
        printf("O valor total da conta industrial é: %.2f reais\n", valor_total_conta);
    }
    else{
        // Informa "Opção inválida" caso o tipo de cobrança seja inválida
        printf("Opção inválida!\n");
    }

    return 0;
}
