#include <stdio.h>

typedef int Item;

#define less(A,B) ((A) < (B))
#define eq(A,B) ((A) == (B))
#define lesseq(A,B) ((A)<=(B))
#define exch(A,B) { Item tt; tt = A; A = B; B = tt; }
#define cmpexch(A,B) {if (less(B,A)) exch(A,B)}

char *bb(Item *v, int l, int r, int b)
{
    if (r<l)
        return "nao";
    
    int meio = (l+r)/2;
    
    if (eq(b,v[meio]))
        return "sim";
    
    else if (less(b,v[meio]))
        return bb(v, l, meio-1, b);
    
    else if (less(v[meio], b))
        return bb(v, meio+1, r, b);
}

void merge(Item *v, int l, int m, int r)
{
    Item *aux = malloc(sizeof(Item) * (r - l + 1));
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r)
    {
        if (lesseq(v[i], v[j]))
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }

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
    int n;
    scanf("%d", &n);

    Item n_proibidos[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &n_proibidos[i]);
    
    mergesort(n_proibidos, 0, n-1);

    int num;
    while (scanf("%d", &num) == 1)
        printf("%s\n", bb(n_proibidos, 0, n-1, num));

    return 0;
}