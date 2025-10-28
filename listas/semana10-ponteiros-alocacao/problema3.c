#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* misturar(char *str1, char *str2){
    int t1 = strlen(str1);
    int t2 = strlen(str2);
    char *nova;
    int i, j, pos;
    int menor;
    
    // Aloca espaço pras duas strings juntas
    nova = (char*) malloc((t1 + t2 + 1) * sizeof(char));
    
    // Descobre qual é a menor
    if(t1 < t2){
        menor = t1;
    }
    else{
        menor = t2;
    }
    
    // Intercala as letras
    pos = 0;
    for(i = 0; i < menor; i++){
        nova[pos] = str1[i];
        pos++;
        nova[pos] = str2[i];
        pos++;
    }

    // Coloca o resto da string maior
    for(j = menor; j < t1; j++){
        nova[pos] = str1[j];
        pos++;
    }
    for(j = menor; j < t2; j++){
        nova[pos] = str2[j];
        pos++;
    }
    
    nova[pos] = '\0';

    return nova;
}

int main()
{
    char s1[101], s2[101];
    char *result;
    int tam;
    
    // Lê as strings
    fgets(s1, 101, stdin);
    fgets(s2, 101, stdin);
    
    // Tira o \n do final e substitui por \0
    tam = strlen(s1);
    if(s1[tam-1] == '\n'){
        s1[tam-1] = '\0';
    }
    
    tam = strlen(s2);
    if(s2[tam-1] == '\n'){
        s2[tam-1] = '\0';
    }
    
    result = misturar(s1, s2);
    
    printf("%s\n", result);
    
    free(result);
    
    return 0;
}