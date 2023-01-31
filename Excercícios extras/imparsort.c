#include <stdio.h>

typedef int Item;

#define Key(A) ((A))
#define less(A,B) ((A) < (B))
#define lesseq(A,B) (Key(A)<=Key(B))
#define eq(A,B) (Key(A)==Key(B))
#define exch(A,B) { Item tt; tt = A; A = B; B = tt; }
#define cmpexch(A,B) {if (less(B,A)) exch(A,B)}

void merge(Item *v, int l, int m, int r)
{
    Item *aux = malloc(sizeof(Item) * (r - l + 1));
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r)
    {
        if (v[i]%2==0 && v[j]%2!=0)
            aux[k++] = v[i++];
        else if (v[i]%2!=0 && v[j]%2==0)
            aux[k++] = v[j++];
        else
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
    Item v[6] = {30, 44, 1, 93, 44, 77};

    mergesort(v, 0, 5);

    for (int i = 0; i < 6; i++)
    {    
        if (i == 5) 
            printf("%d\n", v[i]);
        else 
            printf("%d ", v[i]);
    }
    
    return 0;
}