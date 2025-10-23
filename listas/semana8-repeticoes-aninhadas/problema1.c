#include <stdio.h>

int main()
{
    int m;
    int n;
    int sorteados[30], apostados[50];
    int acertos = 0;

    scanf("%d %d", &m, &n);
    // Lê os m números sorteados
    for(int i = 0; i < m; i++){
        scanf("%d", &sorteados[i]);
    }
    // Lê os n números apostados
    for(int i = 0; i < n; i++){
        scanf("%d", &apostados[i]);
    }
    // Para cada número apostado, verifica se está entre os sorteados
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(apostados[i] == sorteados[j]){
                acertos++;
                break;
            }
        }
    }
    printf("%d\n", acertos);
    
    return 0;
}
