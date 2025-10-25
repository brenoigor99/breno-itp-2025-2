#include <stdio.h>

int main() {
    int n;
    int largada[20], chegada[20];
    
    scanf("%d", &n);
    // Lê a ordem de largada
    for(int i = 0; i < n; i++){
        scanf("%d", &largada[i]);
    }
    // Lê a ordem da chegada
    for(int i = 0; i < n; i++){
        scanf("%d", &chegada[i]);
    }
    
    int maior = 0, venc = 0, cont = 0, pos1 = 0, pos2 = 0, ganho;
    // Percorre todos os pilotos
    for(int p = 1; p <= n; p++){
        // Acha as posições do piloto
        for(int i = 0; i < n; i++){
            if(largada[i] == p){
                pos1 = i + 1;
            }
            if(chegada[i] == p){
                pos2 = i + 1;
            }
        }
        // Calcula quantas posições ganhou
        ganho = pos1 - pos2;

        // Pega o ganho do primeiro piloto pra comparar
        if(p == 1){
            maior = ganho;
            venc = p;
            cont = 1;
        }
        else{
            // Compara com os outros pilotos
            if(ganho > maior){
                maior = ganho;
                venc = p;
                cont = 1;
            }
            else if(ganho == maior){
                cont++;
            }
        }
    }
    // Verifica se deu empate
    if(maior <= 0 || cont > 1){
        printf("empate\n");
    }else{
        printf("%d\n", venc);
    }
    
    return 0;
}