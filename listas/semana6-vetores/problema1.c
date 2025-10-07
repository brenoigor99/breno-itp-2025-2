#include <stdio.h>

/*verifica se a resposta está correta*/
int comparar_resposta(int gabarito, int aluno) {
    if (gabarito == aluno) {
        return 1; /*Resposta correta*/
    } else {
        return 0; /*Resposta errada*/
    }
}
/*Exibe o resultado formatado corretamente*/
void exibir_resultado(int acertos) {
    if (acertos == 1) {
        printf("%d acerto\n", acertos); /*Singular*/
    } else {
        printf("%d acertos\n", acertos); /*Plural*/
    }
}

int main() {
    int n;
    int acertos = 0;
    int gabarito[20];
    int resposta_aluno;
    
    scanf("%d", &n);
    
    /*lê o gabarito*/
    for (int i = 0; i < n; i++) {
        scanf("%d", &gabarito[i]);
    }
    /*lê respostas do aluno e vai somando acertos*/
    for (int i = 0; i < n; i++) {
        scanf("%d", &resposta_aluno);
        acertos = acertos + comparar_resposta(gabarito[i], resposta_aluno);
    }

    exibir_resultado(acertos);
    
    return 0;
}