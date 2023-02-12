#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define less(A,B) ((A) < (B))
#define eq(A,B) ((A) == (B))
#define lesseq(A,B) ((A)<=(B))
#define exch(A,B) { Item tt; tt = A; A = B; B = tt; }
#define cmpexch(A,B) {if (less(B,A)) exch(A,B)}

void merge(Item *v, int l, int m, int r)
{
    Item *aux = malloc(sizeof(Item) * (r - l + 1));
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r)
        if (lesseq(v[i], v[j]))
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];

    while (i <= m)
        aux[k++] = v[i++];
    while (j <= r)
        aux[k++] = v[j++];

    k = 0;
    for (i = l; i <= r; i++)
        v[i] = aux[k++];
    
    free(aux);
}

void mergesort(Item *v, int l, int r)
{
    if (l >= r) return;

    int meio = l+(r-l)/2;

    mergesort(v, l, meio);
    mergesort(v, meio+1, r);
    merge(v, l, meio, r);
}


int main(void)
{
    int vetor[8*100000];
    int tamanho;

    int count = 0;
    while (scanf("%d", &tamanho) == 1)
        for (int i = 0; i < tamanho; i++)
            scanf("%d", &vetor[count++]);

    mergesort(vetor, 0, count-1);
    
    for (int j = 0; j < count; j++) 
        if (j == count-1) 
            printf("%d\n", vetor[j]);
        else 
            printf("%d ", vetor[j]);
}