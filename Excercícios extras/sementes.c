#include <stdio.h>

typedef struct
{
    int codigo;
    int nota;
} Item;

#define Key(A) ((A).nota)
#define less(A,B) ((A) < (B))
#define lesseq(A,B) (Key(A)<=Key(B))
#define eq(A,B) (Key(A)==Key(B))
#define exch(A,B) { Item tt; tt = A; A = B; B = tt; }
#define cmpexch(A,B) {if (less(B,A)) exch(A,B)}

void merge(Item *v, int l, int m, int r)
{
    Item *aux = malloc(sizeof(Item)*(r - l + 1));
    
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r)
    {
        if (eq(v[i], v[j]))
            if (less(v[i].codigo, v[j].codigo))
                aux[k++] = v[i++];
            else
                aux[k++] = v[j++];    
        else if (less(v[i].nota, v[j].nota))
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
    if (l>=r) return;

    int meio = l+(r-l)/2;

    mergesort(v, l, meio);
    mergesort(v, meio+1, r);
    merge(v, l, meio, r);
}

int main(void)
{
    int k;
    scanf("%d", &k);
    int n = 7;

    Item sementes[n];
    for (int i = 0; i < n; i++)
    {
        Item tmp;
        scanf("%d %d", &tmp.codigo, &tmp.nota);
        sementes[i] = tmp;
    }    

    mergesort(sementes, 0, n-1);

    for (int i = 0; i < k; i++)
        printf("%d %d\n", sementes[i].codigo, sementes[i].nota);
    
    return 0;
}