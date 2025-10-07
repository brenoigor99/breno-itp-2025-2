#include <stdio.h>

int main()
{
    char jogador1, jogador2;

    printf("Use P para pedra, A para papel e T para tesoura\n\n");
    
    printf("Digite a jogada do primeiro jogador: \n");
    scanf(" %c", &jogador1);

    printf("Digite a jogada do segundo jogador: \n");
    scanf(" %c", &jogador2);

    /*Verifica se houve empate (jogadas iguais)*/
    if(jogador1 == jogador2){
        printf("Empate!");
    }
    /*Verifica as condições de vitória do jogador 1*/
    /*Papel(A) vence Pedra(P), Pedra(P) vence Tesoura(T), Tesoura(T) vence Papel(A)*/
    else if(jogador1 == 'A' && jogador2 == 'P' || jogador1 == 'P' && jogador2 == 'T' ||
        jogador1 == 'T' && jogador2 == 'A'){
        printf("jogador 1 venceu!\n");
    }
    /*Verifica as condições de vitória do jogador 2*/
    /*Tesoura(T) vence Papel(A), Papel(A) vence Pedra(P), Pedra(P) vence Tesoura(T)*/
    else if(jogador1 == 'A' && jogador2 == 'T' || jogador1 == 'P' && jogador2 == 'A' ||
        jogador1 == 'T' && jogador2 == 'P'){
        printf("jogador 2 venceu!\n");
    }
    else{
        /*Se nenhuma condição anterior foi atendida, a jogada é inválida*/
        printf("jogada inválida! Digite apenas os dígitos P, A ou T. \n");
    }

    return 0;
}
