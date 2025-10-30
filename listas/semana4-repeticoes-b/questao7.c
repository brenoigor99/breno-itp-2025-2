#include <stdio.h>

int main()
{
    int a, b, eh_primo;

    do{
        // Garante que 'a' seja maior que 'b' (solicita nova entrada até que a condição seja atendida)
        printf("Digite o valor do a: \n");
        scanf("%d", &a);
        printf("Digite o valor de b: ");
        scanf("%d", &b);
    }
    while(a <= b); // Repete enquanto 'a' for menor ou igual a 'b'

    printf("Primos entre %d e %d: ", b, a);

    // Loop que percorre todos os números no intervalo de b até a
    for(int i = b; i <= a; i++){
        eh_primo = 1; // Assume inicialmente que o número é primo
        
        if(i < 2){
            eh_primo = 0; // Números menores que 2 não são primos
        }
        // Testa se o número é divisível por algum valor de 2 até raiz de i
        for(int j = 2; j * j <= i && eh_primo; j++){
            if(i % j == 0){
                eh_primo = 0;
            }
        }

        if(eh_primo){
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
