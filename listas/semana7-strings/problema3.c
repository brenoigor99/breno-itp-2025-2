#include <stdio.h>
#include <string.h>

int main()
{
    char aluno_buscado[11];
    char frequencias[1001];
    char palavra[11];

    /*Leitura do nome do aluno*/
    scanf("%s", aluno_buscado);
    getchar(); /*remove o \n que sobrou no buffer*/

    /*Lê a string das frequências até 1000 caracteres*/
    fgets(frequencias, 1001, stdin);

    int total_aulas = 0;
    int aulas_presentes = 0;
    int em_aula = 0;
    int aluno_presente = 0;
    int faltas;
    int i = 0;

    /*Percorre a string extraindo cada palavra*/
    while(frequencias[i] != '\0'){
        /*Pula espaços e também quebras de linha*/
        while(frequencias[i] == ' ' || frequencias[i] == '\n'){
            i++;
        }

        int j = 0;
        /*Copia a palavra atual*/
        while(frequencias[i] != ' ' && frequencias[i] != '\n' && frequencias[i] != '\0'){
            palavra[j] = frequencias[i];
            i++;
            j++;
        }
        palavra[j] = '\0';

        if(j > 0){
            /*Checa se é uma data (tem 5 caracteres e uma barra no meio)*/
            if(strlen(palavra) == 5 && palavra[2] == '/'){
                /*Se já tava em aula antes, precisa finalizar ela*/
                if(em_aula && aluno_presente){
                    aulas_presentes++; /*Conta mais uma presença*/
                }
                /*Começa uma nova aula*/
                total_aulas++;
                em_aula = 1;
                aluno_presente = 0;
            }
            /*Se não for data, então é o nome do aluno*/
            else{
                /*Verifica se é o aluno que buscamos*/
                if(strcmp(palavra, aluno_buscado) == 0){
                    aluno_presente = 1;
                }
            }
        }
    }

    if(em_aula && aluno_presente){
        aulas_presentes++;
    }
    /*Calcula quantas faltas ele teve*/
    faltas = total_aulas - aulas_presentes;

    printf("%d\n", faltas);

    return 0;
}
