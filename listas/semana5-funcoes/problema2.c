#include <stdio.h>

int eh_primo(int n){
    if(n <= 1){
        return 0;
    }

    if(n == 2){
        return 1;
    }

    if(n % 2 == 0){
        return 0;
    }
    // Testa divisibilidade apenas por números ímpares até a raiz quadrada de n
    for(int i = 3; i * i <= n; i+=2){
        if(n % i == 0){
            return 0; // Encontrou um divisor, não é primo
        }
    }
    return 1; // Não encontrou divisores, é primo
}

int main() 
{
    // Busca triplas primas na forma (p, p+2, p+6) até 50000
    for(int x = 2; x <= 50000; x++){
        if(eh_primo(x) && eh_primo(x + 2) && eh_primo(x + 6)){
            printf("(%d, %d, %d)\n", x, x + 2, x + 6);
        }
    }
    
    return 0;
}