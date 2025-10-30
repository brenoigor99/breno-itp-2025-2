#include <stdio.h>

int main() 
{
    int cont = 0;
    
    // Testa todas as combinações possíveis de posições das 4 rainhas
    // c0, c1, c2, c3 = coluna da rainha nas linhas 0, 1, 2, 3 respectivamente
    for (int c0 = 0; c0 < 4; c0++){
        for (int c1 = 0; c1 < 4; c1++){
            for (int c2 = 0; c2 < 4; c2++){
                for (int c3 = 0; c3 < 4; c3++){ 
                    int valida = 1;
                    // Verifica ataques na mesma coluna
                    if (c0 == c1 || c0 == c2 || c0 == c3 || c1 == c2 || c1 == c3 || c2 == c3){
                        valida = 0;
                    }
                    // Verifica ataques nas diagonais (diferença de colunas == diferença de linhas)
                    if (c0 - c1 == 0 - 1 || c0 - c1 == 1 - 0){
                        valida = 0;
                    }
                    if (c0 - c2 == 0 - 2 || c0 - c2 == 2 - 0){
                        valida = 0;
                    }
                    if (c0 - c3 == 0 - 3 || c0 - c3 == 3 - 0){
                        valida = 0;
                    } 
                    if (c1 - c2 == 1 - 2 || c1 - c2 == 2 - 1){
                        valida = 0;
                    } 
                    if (c1 - c3 == 1 - 3 || c1 - c3 == 3 - 1){
                        valida = 0;
                    }
                    if (c2 - c3 == 2 - 3 || c2 - c3 == 3 - 2){
                        valida = 0;
                    } 
                    
                    // Se passou em todas as validações, imprime a solução
                    if (valida){
                        cont++;
                        printf("Solução %d:\n", cont);
                        
                        for (int i = 0; i < 4; i++){
                            for (int j = 0; j < 4; j++){
                                if ((i == 0 && j == c0) || (i == 1 && j == c1) || 
                                    (i == 2 && j == c2) || (i == 3 && j == c3)){
                                    printf("Q ");
                                }else{
                                    printf(". ");
                                }
                            }
                            printf("\n");
                        }
                        printf("\n");
                    }
                }
            }
        }
    }
    
    printf("Total: %d soluções\n", cont);

    return 0;
}