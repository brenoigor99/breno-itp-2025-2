#include <stdio.h>

int main() {
    int total_figurinhas, figurinhas_que_tenho;
    
    scanf("%d %d", &total_figurinhas, &figurinhas_que_tenho);
    
    int minhas_figurinhas[1000];
    
    // Lê os números de todas as figurinhas que já possuo
    for(int i = 0; i < figurinhas_que_tenho; i++){
        scanf("%d", &minhas_figurinhas[i]);
    }
    // Percorre todos os números possíveis de figurinhas (1 até o total)
    for(int numero = 1; numero <= total_figurinhas; numero++){
        
        int tenho_essa = 0;
        
        // Verifica se o número atual está na minha coleção
        for (int i = 0; i < figurinhas_que_tenho; i++) {
            if(minhas_figurinhas[i] == numero){
                tenho_essa = 1;
                break;
            }
        }
        // Se não tenho essa figurinha, imprime as faltantes
        if (tenho_essa == 0) {
            printf("%d ", numero);
        }
    }
    printf("\n");

    return 0;
}