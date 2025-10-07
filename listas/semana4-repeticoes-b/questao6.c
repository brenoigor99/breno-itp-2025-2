#include <stdio.h>

int main()
{
    int cont = 0;

    /*busca trios pitagóricos de 1 até 999*/
    for(int a = 1; a < 1000; a++){
        for(int b = a; b < 1000; b++){ /*b >= a para evitar duplicatas*/
            for(int c = b; c < 1000; c++){ /*c >= b para manter ordem crescente*/
                if((a*a) + (b*b) == (c*c)){
                    printf("(%d %d %d)\n", a, b, c);
                    cont++;
                    break; /*Sai do loop de 'c' após encontrar a primeira hipotenusa válida*/
                }
            }
        }
    }
    printf("\n");
    printf("Total de trio pitagóricos: %d\n", cont);
    
    return 0;
}
