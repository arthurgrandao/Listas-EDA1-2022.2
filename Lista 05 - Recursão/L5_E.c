#include <stdio.h>

void somal(int *vetor, int *fim, int soma,  int limite)
{
    if (fim >= vetor)
    {
        soma += vetor[0];
        if (soma > limite)
        {
            somal(vetor+1, 0, fim, limite);
            printf("%d\n", vetor[0]);
        }
        else
            somal(vetor+1, soma, fim, limite);
    }
    else
        return;
}

int main(void) 
{
    int temp = -1, size = 0;
    int limite = 0;
    int v[1000];

    while (scanf("%d", &temp) && temp != 0)
    {
        v[size] = temp;
        size++;
    }

    scanf("%d", &limite);

    somal(v, &v[size], 0, limite);
}