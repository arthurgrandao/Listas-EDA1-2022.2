#include <stdio.h>

int main() 
{
    char resposta[4];
    int *resposta_p = resposta;
    char sim[4] = "sim\0";
    int *sim_p = sim;
    
    int c_sim = 0, c_triagem = 0, c_questao = 0;

    while (scanf("%s", resposta) == 1) 
    {
        c_questao++;

        if (c_questao >= 11) 
        {
            c_sim = 0;
            c_questao = 1;
        }

        if (*resposta_p == *sim_p) 
            c_sim++;

        if ((c_sim >= 2) && (c_questao == 10))
            c_triagem++;
    }

    printf("%d\n", c_triagem);

}