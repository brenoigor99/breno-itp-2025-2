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

    int menor_resto = quantia;

    int melhor_i = 0;
    int melhor_j = 0;

    // Busca a combinação que maximiza o uso do orçamento (minimiza o resto)
    for(int i = 0; i <= 10; i++){
        for(int j = 0; j <= 10; j++){
            custo_total = i * preco1 + j * preco2;
            if(custo_total <= quantia){
                resto = quantia - custo_total;
                // Atualiza se encontrou combinação melhor
                if(resto < menor_resto){
                menor_resto = resto;
                melhor_i = i;
                melhor_j = j;
            }
        }
    }
}
    printf("Resta menos comprando %d do primeiro e %d do segundo:\n", melhor_i, melhor_j);
    
    return 0;
}