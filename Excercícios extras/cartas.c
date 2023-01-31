#include <stdio.h>

int cartas(int *vetor, int *descartados, int n)
{
    if (n > 1)
    {
        int vetor2[n-1];
        
        descartados[0] = vetor[0];
        vetor2[n-2] = vetor[1];
        
        for (size_t i = 0; i < n-2; i++)
            vetor2[i] = vetor[i+2];
        
        cartas(vetor2, descartados+1, n-1);
    }
    else
        return vetor[0];
}

int main(void)
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0)
            break;

        int vetor[n];

        for (size_t i = 1; i <= n; i++)
            vetor[i-1] = i;
        
        int descartados[n-1];
        int remaining = cartas(vetor, descartados, n);
        
        printf("Discarded cards: ");
        for (size_t i = 0; i < n-1; i++)
            printf("%d, ", descartados[i]);
        
        printf("\b\b \n");
        printf("Remaining card: %d\n", remaining);
    }
}