#include <stdio.h>

int modulo(int x, int y)
{
    int sub = x - y;
    if (sub < 0)
        return sub * (-1);
    return sub;
}

int main(void)
{
    int batidas[2] = {0, 0},
        pontos[2] = {0, 0},
        n_cobr = 0;

    scanf("%d", &n_cobr);

    char cobrancas[2][n_cobr];

    scanf("%s %s", &cobrancas[0][0], &cobrancas[1][0]);

    for (size_t rodada = 0; rodada < n_cobr; rodada++)
    {

        for (size_t time = 0; time < 2; time++)
        {
            batidas[time]++;

            if (cobrancas[time][rodada] == 'o')
                pontos[time] += 1;
            
            int vantagem = pontos[time]-pontos[modulo(time, 1)];
            
            if (vantagem < 0)
            {
                if (n_cobr-batidas[time] + vantagem < 0)
                {
                    printf("%d\n", batidas[0] + batidas[1]);
                    return 0;
                }
            }
            else
            {
                if (n_cobr-batidas[modulo(time, 1)] < vantagem)
                {
                    printf("%d\n", batidas[0] + batidas[1]);
                    return 0;
                }
            }
        }
    }

    printf("Empate\n");
    return 0;
}
