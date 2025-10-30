#include <stdio.h>

int main()
{
    int n, cont = 1;

    printf("Digite o valor do n: \n");
    scanf("%d", &n);

    // Gera pirâmide de números sequenciais
    for(int i = 1; i <= n; i++){
        // Imprime i números na linha i
        for(int j = 1; j <= i; j++){
            printf("%d ", cont);
            cont++;
        }
        printf("\n");
    }
    
    return 0;
}
