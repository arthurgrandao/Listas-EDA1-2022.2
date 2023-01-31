#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define key(A) (A)
#define less(A, B) (A < B)
#define lesseq(A, B) (A <= B)
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

int remover_duplicadas(Item *v, int n)
{
    int t = 1;
    for (int i = 1; i < n; i++)
        if (v[i] != v[t - 1])
            v[t++] = v[i];
    return t;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    Item *v = malloc(sizeof(int) * (2*n));
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    mergesort(v, 0, n-1);

    int t1 = remover_duplicadas(v, n);

    if (t1 % 2 != 0)
        v[t1++] = 1000000000;

    int t2 = 0;
    for (int i = 0; i < t1-1; i += 2)
        v[t1+(t2++)] = v[i] + v[i+1];
    
    merge(v, 0, t1-1, (t1+t2)-1);

    t1 = remover_duplicadas(v, t1+t2);
   
    for (int i = 0; i < t1; i+=4)
        printf("%d\n", v[i]);
    printf("Elementos: %d\n", t1);

    return 0;
}