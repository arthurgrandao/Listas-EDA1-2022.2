#include <stdio.h>

int balanceada(int *vetor, int inicio, int fim)
{
    if (fim - inicio == 1) // ou (inicio > fim)
        return 1;

    if ((vetor[inicio]+vetor[fim]) == (vetor[inicio+1] + vetor[fim-1]))
        return balanceada(vetor, inicio+1, fim-1);
    
    else
        return 0;
}

int main(void)
{
    int vetor1[6] = {1, 3, 7, 11, 15, 17};
    int vetor2[12] = {3, 3, 5, 8, 9, 10, 11, 27, 32, 41, 45, 51};

    printf("%d\n", balanceada(vetor1, 0, 5));
    printf("%d\n", balanceada(vetor2, 0, 11));
}