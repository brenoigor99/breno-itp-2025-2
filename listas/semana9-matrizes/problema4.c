#include <stdio.h>

int main() 
{
    int m, x, z;
    int preco[10][10];
    int i, j;
    int menor_custo;
    int cidade_intermediaria;
    
    scanf("%d", &m);
    
    // Lê a matriz de preços
    for(i = 0; i < m; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &preco[i][j]);
        }
    }
    
    scanf("%d %d", &x, &z);

    // Começa com a viagem direta
    menor_custo = preco[x][z];
    cidade_intermediaria = -1;
    
    // Testa viagens com 1 parada
    for(i = 0; i < m; i++){
        if(i != x && i != z && preco[x][i] > 0 && preco[i][z] > 0) {
            int custo_total = preco[x][i] + preco[i][z];
            if(custo_total < menor_custo) {
                menor_custo = custo_total;
                cidade_intermediaria = i;
            }
        }
    }
    // Imprime o resultado
    if(cidade_intermediaria == -1){
        printf("%d-%d R$%d\n", x, z, menor_custo);
    }
    else{
        printf("%d-%d-%d R$%d\n", x, cidade_intermediaria, z, menor_custo);
    }
    
    return 0;
}