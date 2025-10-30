#include <stdio.h>
#include <stdlib.h>

int* alocarVetor(int n){
    int* vetor;
    vetor = (int*) malloc(n * sizeof(int));
    return vetor;
}

int* somaVetores(int* u, int* v, int n){
    int* resultado;
    int i;
    
    resultado = alocarVetor(n);
    
    for(i = 0; i < n; i++) {
        resultado[i] = u[i] + v[i];
    }
    
    return resultado;
}

int main()
{
    int n1, n2;
    int* u;
    int* v;
    int* soma;
    int i;
    
    scanf("%d %d", &n1, &n2);
    
    // Aloca os vetores
    u = alocarVetor(n1);
    v = alocarVetor(n2);
    
    // Lê os valores de u
    for(i = 0; i < n1; i++){
        scanf("%d", &u[i]);
    }

    // Lê os valores de v
    for(i = 0; i < n2; i++){
        scanf("%d", &v[i]);
    }

    // Verifica se as dimensões são compatíveis
    if(n1 != n2){
        printf("dimensoes incompativeis\n");
    }
    else{
        soma = somaVetores(u, v, n1);
        // Imprime o resultado
        for(i = 0; i < n1; i++) {
            printf("%d", soma[i]);
            if(i < n1 - 1) {
                printf(" ");
            }
        }
        printf("\n");
        
        free(soma);
    }

    // Libera a memória
    free(u);
    free(v);
    
    return 0;
}