#include <stdio.h>

int main() 
{
    float p, q;

    printf("Digite o preço de venda p: ");
    scanf("%f", &p);
    
    printf("Digite o preço de produção q: ");
    scanf("%f", &q);
    
    float melhor_razao = 0.0;
    int melhor_x = 0;
    int melhor_y = 0;
    
    /*busca a melhor promoção "leve x pague y" que não dê prejuízo*/
    for (int x = 2; x <= 10; x++){
        for (int y = 1; y < x; y++){
            float receita = y * p;
            float custo = x * q;
            /*Verifica se a promoção não dá prejuízo (receita ≥ custo)*/
            if (receita >= custo) {
                float razao = (float)x / y;
                /*Se esta promoção tem razão maior, atualiza a melhor opção*/
                if (razao > melhor_razao) {
                    melhor_razao = razao;
                    melhor_x = x;
                    melhor_y = y;
                }
            }
        }
    }
    if(melhor_x > 0){
        printf("A melhor promoção eh: leve %d pague %d\n", melhor_x, melhor_y);
    }
    else{
        printf("Nenhuma promoção viável encontrada (todas dariam prejuízo)\n");
    }
    
    return 0;
}