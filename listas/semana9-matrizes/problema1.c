#include <stdio.h>

int main() 
{
    int m, n, i, j;
    int campo[10][10];
    int coberto[10][10];
    int ferteis_cobertos = 0;
    int ferteis_nao_cobertos = 0;
    
    scanf("%d %d", &m, &n);
    
    // Lê o campo e inicializa matriz de cobertura
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &campo[i][j]);
            coberto[i][j] = 0;
        }
    }
    // Marca os setores cobertos pelos irrigadores
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++){
            if(campo[i][j] == 2){
                // Norte
                if(i > 0){
                    coberto[i-1][j] = 1;
                }
                // Sul
                if(i < m-1){
                    coberto[i+1][j] = 1;
                }
                // Oeste
                if(j > 0){
                    coberto[i][j-1] = 1;
                }
                // Leste
                if(j < n-1){
                    coberto[i][j+1] = 1;
                }
            }
        }
    }
    // Conta setores férteis cobertos e não cobertos
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(campo[i][j] == 1){
                if(coberto[i][j] == 1){
                    ferteis_cobertos++;
                }
                else{
                    ferteis_nao_cobertos++;
                }
            }
        }
    }
    
    printf("%d %d\n", ferteis_cobertos, ferteis_nao_cobertos);
    
    return 0;
}