#include <stdio.h>

int main() 
{
    int m, usuario;
    int amizades[100][100];
    int sugestoes[100];
    int total = 0;
    int i, j, k;
    int achou;
    
    scanf("%d", &m);
    
    // lê a matriz de amizades
    for(i = 0; i < m; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &amizades[i][j]);
        }
    }
    // Lê o usuário que vai receber as sugestões
    scanf("%d", &usuario);
    
    // Percorre todos os usuários buscando sugestões
    for(i = 0; i < m; i++) {
        // Verifica se não é ele mesmo e se não são amigos
        if(i != usuario && amizades[usuario][i] == 0) {
            achou = 0;
            // Procura amigos em comum
            for(k = 0; k < m; k++) {
                if(amizades[usuario][k] == 1 && amizades[i][k] == 1) {
                    achou = 1;
                    break;
                }
            }
            // Se encontrou amigo em comum, adiciona nas sugestões
            if(achou == 1) {
                sugestoes[total] = i;
                total++;
            }
        }
    }
    // Imprime as sugestões
    if(total == 0) {
        printf("0\n");
    } else {
        for(i = 0; i < total; i++) {
            printf("%d", sugestoes[i]);
            if(i < total - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}