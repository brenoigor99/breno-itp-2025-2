#include <stdio.h>

int main()
{
    int preco1;
    printf("Digite o preço do primeiro fornecedor: \n");
    scanf("%d", &preco1);

    int preco2;
    printf("Digite o preço do segundo fornecedor: \n");
    scanf("%d", &preco2);

    int quantia;
    printf("Digite a quantia disponível: \n");
    scanf("%d", &quantia);

    int custo_total = 0, resto;

    // Loop externo: testa quantidade de produtos do primeiro fornecedor (0 a 10)
    for(int i = 0; i <= 10; i++){
        for(int j = 0; j <= 10; j++){
            custo_total = i * preco1 + j * preco2;
            // Verifica se a combinação está dentro do orçamento disponível
            if(custo_total <= quantia){
                resto = quantia - custo_total;
                printf("Comprando %d do primeiro e %d do segundo resta: %d\n", i, j, resto);
            }
        }
    }
    
    return 0;
}