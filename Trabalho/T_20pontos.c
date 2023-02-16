#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    unsigned long long int atual, ant, prox;
} Item;

#define key(A) (A.atual)
#define less(A,B) (key(A) < key(B))
#define exch(A, B) {Item tt = A; A = B; B = tt;}
#define cmpexch(A, B) {if(less(B, A)) exch(A, B);}


int partition(Item *v, int l, int r)
{
    Item p = v[r];
    int i = l - 1, j = r;
    for(;;)
    {
        while (less(v[++i], p));
        while (less(p, v[--j])) if (j == l) break;
        if (j <= i) break;
        exch(v[j], v[i]);
    }
    exch(v[i], v[r]);
    return i;
}

void insertionsort(Item *v, int l, int r)
{
    for (int i = r; i > l; i--)
    {
        cmpexch(v[i - 1], v[i]);
    }
    for (int i = l + 2; i <= r; i++)
    {
        Item mao = v[i];
        int j = i;
        while (less(mao, v[j - 1]))
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = mao;
    }    
}

void quicksortM3(Item *v, int l, int r)
{
    if (r - l + 1 <= 16) return;
    exch(v[(l+r)/2], v[r - 1]);
    cmpexch(v[l], v[r]);
    cmpexch(v[l], v[r - 1]);
    cmpexch(v[r - 1], v[r]);
    int j = partition(v, l + 1, r - 1);
    quicksortM3(v, l, j - 1);
    quicksortM3(v, j + 1, r);
}

void quicksort(Item *v, int l, int r)
{
    quicksortM3(v, l, r);
    insertionsort(v, l, r);
}

int buscabinaria(Item *v, int l, int r, Item b)
{
    if(r < l) return - 1;
    int meio = l + (r - l)/2;
    if (less(b, v[meio])) buscabinaria(v, l, meio - 1, b);
    else if (less(v[meio], b)) buscabinaria(v, meio + 1, r, b);
    else return meio;
}

int sana(Item *v, Item ptr1, Item ptr2, int r)
{
    if (ptr1.prox == ptr2.atual && ptr2.ant == ptr1.atual) return 1;
    Item prox = {ptr1.prox, 0, 0};
    int j = buscabinaria(v, 0, r, prox);
    if (j == -1 || ptr1.atual != v[j].ant)
        return 0;
    return sana(v, v[j], ptr2, r);
}

Item v[700000];

int main(void)
{
    int i = 0;
    while (scanf("%llx %llx %llx", &v[i].atual,  &v[i].ant,  &v[i].prox) == 3) i++;   
    Item ptr1 = v[0];
    Item ptr2 = v[1];   
    quicksort(v, 0, i);
    printf(sana(v, ptr1, ptr2, i) ? "sana\n" : "insana\n");
    return 0;
}