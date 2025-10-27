#include <stdio.h>

int main() 
{
    int m;
    int gols[20][20];
    int empates = 0;
    int i, j;
    
    scanf("%d", &m);
    
    // Lê a matriz de gols
    for(i = 0; i < m; i++){
        for(j = 0; j < m; j++) {
            scanf("%d", &gols[i][j]);
        }
    }
    // Conta os empates
    for(i = 0; i < m; i++){
        for(j = i + 1; j < m; j++){
            if(gols[i][j] == gols[j][i]){
                empates++;
            }
        }
    }
    
    printf("%d\n", empates);
    
    return 0;
}