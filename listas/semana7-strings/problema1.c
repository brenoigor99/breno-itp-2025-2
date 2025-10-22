#include <stdio.h>
#include <string.h>

int main()
{
    char campo[21];
    int indice;
    int bombas = 0; /*Contador de bombas*/

    scanf("%s", campo);

    scanf("%d", &indice);

    int tamanho = strlen(campo);

    /*Verifica se há uma bomba no índice*/
    if(campo[indice] == 'x'){
        printf("bum!\n");
    }
    else{
        /*Verifica se há bombas na esquerda*/
        if(indice > 0 && campo[indice - 1] == 'x'){
        bombas++;
        }
        /*Verifica se há bombas na direita*/
        if(indice < tamanho - 1 && campo[indice + 1] == 'x'){
        bombas++;
        }

    printf("%d\n", bombas);

    }

    return 0;
}
