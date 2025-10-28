#include <stdio.h>
#include <stdlib.h>

int* buscaNoVetor(int *v, int n, int valor, int *qtd){
    int *indices;
    int i;
    int cont = 0;
    
    // Primeiro conta quantas ocorrências existem
    for(i = 0; i < n; i++) {
        if(v[i] == valor) {
            cont++;
        }
    }
    
    // Se não encontrou nenhuma
    if(cont == 0) {
        *qtd = 0;
        return NULL;
    }
    
    // Aloca vetor para guardar os índices
    indices = (int*) malloc(cont * sizeof(int));
    
    // Preenche o vetor de índices
    *qtd = 0;
    for(i = 0; i < n; i++) {
        if(v[i] == valor) {
            indices[*qtd] = i;
            (*qtd)++;
        }
    }
    
    return indices;
}

int main()
{
    int n, valor;
    int *vetor;
    int *resultado;
    int qtd;
    int i;
    
    scanf("%d", &n);
    
    // Aloca o vetor
    vetor = (int*) malloc(n * sizeof(int));
    
    // Lê os valores
    for(i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    
    scanf("%d", &valor);
    
    // Busca o valor no vetor
    resultado = buscaNoVetor(vetor, n, valor, &qtd);
    
    if(resultado == NULL){
        printf("Nenhuma ocorrencia\n");
    }
    else{
        printf("%d\n", qtd);
        for(i = 0; i < qtd; i++){
            printf("%d", resultado[i]);
            if(i < qtd - 1){
                printf(" ");
            }
        }
        printf("\n");
        
        free(resultado);
    }
    
    free(vetor);
    
    return 0;
}