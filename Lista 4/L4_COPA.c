#include <stdio.h>

int main(void)
{
    int ntimes = 0;
    int jogos = 0;
    
    while (scanf("%d %d", &ntimes, &jogos) == 2)
    {
        if (ntimes == 0)
            break;

        int total = jogos*3;
        int pts = 0;
        
        int pontos = 0;
        for (size_t i = 0; i < ntimes; i++)
        {
            scanf("%*s %d", &pontos);
            pts += pontos;
        }

        printf("%d\n", total-pts);
    }
}