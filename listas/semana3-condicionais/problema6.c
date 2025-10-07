#include <stdio.h>

int main()
{
    char febre, tosse, dor_de_cabeça, dor_no_corpo;
    printf("Responda ao questionário utilizando apenas letras maiúsculas (S/N)\n\n");

    /*Coleta dos sintomas do usuário*/
    printf("Você tem febre? (S/N)\n");
    scanf(" %c", &febre);
    
    printf("Você tem tosse? (S/N)\n");
    scanf(" %c", &tosse);

    printf("Tem dor de cabeça? (S/N)\n");
    scanf(" %c", &dor_de_cabeça);

    printf("Você sente dor no corpo? (S/N)\n");
    scanf(" %c", &dor_no_corpo);

    /*Verifica sintomas de gripe (febre + dor de cabeça + dor no corpo)*/
    if(febre == 'S' && dor_de_cabeça == 'S' && dor_no_corpo == 'S'){
        printf("Possível gripe\n");
    }
    /*Verifica sintomas de resfriado (tosse + febre)*/
    else if(tosse == 'S' && febre == 'S'){
        printf("Possível resfriado\n");
    }
    /*Verifica sintomas de enxaqueca (apenas dor de cabeça, sem outros sintomas)*/
    else if(dor_de_cabeça == 'S' && febre == 'N' && tosse == 'N' && dor_no_corpo == 'N'){
        printf("Possível enxaqueca\n");
    }
    /*Verifica se há apenas febre isolada*/
    else if(febre == 'S' && dor_de_cabeça == 'N' && tosse == 'N' && dor_no_corpo == 'N'){
        printf("Consulte um médico\n");
    }
    /*Verifica se não há nenhum sintoma*/
    else if(febre == 'N' && dor_de_cabeça == 'N' && dor_no_corpo == 'N' && tosse == 'N'){
        printf("Você parece estar bem\n");
    }
    /*Para combinações de sintomas não especificadas, recomenda-se uma consulta médica*/
    else{
        printf("Consulte um médico para avaliação\n");
    }
    
    return 0;
}
