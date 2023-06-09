/*
 *  Uma sequência de N elementos Vi ORDENADOS, com N par, é dita balanceada quando
 *  a soma do maior elemento com o menor elemento é igual a soma do segundo maior elemento com o segundo
 *  menor elemento, que por sua vez é igual a soma do terceiro maior elemento com o terceiro menor elemento,
 *  e assim por diante. Escreva uma função RECURSIVA em C que decida se o vetor está balanceado ou não.
 *  Esta função deverá retornar 1 quanto estiver balanceado e 0 quando não estiver. Implemente quaisquer
 *  funções auxiliares que achar necessário.
 *  A função tem o seguinte protótipo (e não pode ser modificado):
 *  
 *  int balanceada(int *vetor, int inicio, int fim)
 *  
 *  • 2 ≤ N ≤ 1000
 *  • −1000 ≤ Vi ≤ 1000
 *  
 *  Exemplo de vetor balanceado:
 *  1 3 7 11 15 17
 *  Exemplo de vetor não balanceado:
 *  3 3 5 8 9 10 11 27 32 41 45 51
 */

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