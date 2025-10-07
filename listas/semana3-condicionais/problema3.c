#include <stdio.h>

int main()
{
    float a, b, c, media, media_final, nota_final;
    
    printf("Digite as 3 notas do aluno: \n");
    scanf("%f %f %f", &a, &b, &c);

    /*Calcula a média aritmética das três notas*/
    media = (a + b + c)/3;

    /*Verifica se o aluno foi aprovado direto (média >= 7.0)*/
    if(media >= 7.0){
        printf("Aprovado! %.2f\n", media);
    }
    /*Verifica se o aluno foi para recuperação (média entre 4.0 e 6.99)*/
    else if(media >= 4.0 && media < 7.0){
        printf("Recuperação! %.2f\n", media);
        printf("Digite a nota na recuperação: \n");
        scanf("%f", &nota_final);

        /*Calcula a média final (média anterior + nota de recuperação) / 2*/
        media_final = (media + nota_final)/2;

        /*Verifica se foi aprovado após a recuperação (média final >= 5.0)*/
        if(media_final >= 5.0){
            printf("Aprovado! %.2f\n", media_final);
        }
        /*Se a média for menor que 4.0, o aluno é reprovado direto*/
        else{
            printf("Reprovado! %.2f\n", media_final);
        }
    }
    else{
        printf("Reprovado! %.2f\n", media);
    }

    return 0;
}
