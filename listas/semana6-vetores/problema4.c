#include <stdio.h>

int main() {
    int v[10];
    int visitadas[10] = {0}; // Marca quais ilhas já foram visitadas
    
    for (int i = 0; i < 10; i++) {
        scanf("%d", &v[i]);
    }
    
    int ilha_atual = 0; // Começa sempre na ilha 0
    while (1) {
        // Se já visitou essa ilha antes, encontrou o início do ciclo
        if (visitadas[ilha_atual] == 1) {
            printf("%d\n", ilha_atual);
            break;
        }
        
        visitadas[ilha_atual] = 1; // Marca a ilha como visitada
        ilha_atual = v[ilha_atual]; // Segue para a próxima ilha
    }
    
    return 0;
}