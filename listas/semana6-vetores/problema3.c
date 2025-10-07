#include <stdio.h>

int main() 
{
    int n;
    int alturas[30]; 

    scanf("%d", &n);
    
    /*Lê todas as alturas*/
    for(int i = 0; i < n; i++){
        scanf("%d", &alturas[i]);
    }
    /*Encontra a maior altura do array*/
    int maior_altura = alturas[0];
    for(int i = 1; i < n; i++){
        if(alturas[i] > maior_altura){
            maior_altura = alturas[i]; /*Atualiza se encontrar um maior*/
        }
    }
    
    int primeira_posicao, segunda_posicao;
    int encontrados = 0;
    
    /*Procura as duas primeiras posições onde aparece a maior altura*/
    for(int i = 0; i < n; i++){
        if(alturas[i] == maior_altura){
            encontrados++;
            
            if(encontrados == 1){
                primeira_posicao = i; 
            } 
            else if(encontrados == 2){
                segunda_posicao = i;
                break;
            }
        }
    }
    /*distância entre as posições (excluindo as extremidades)*/
    int comprimento = segunda_posicao - primeira_posicao - 1;
    
    printf("%d\n", comprimento);
    
    return 0;
}