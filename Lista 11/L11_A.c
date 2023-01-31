#include <stdio.h>

typedef int Item;

#define less(A,B) ((A) < (B))
#define exch(A,B) { Item tt; tt = A; A = B; B = tt; }
#define cmpexch(A,B) {if (less(B,A)) exch(A,B)}

int separa(Item *v, int l, int r)
{
    int j = l;
    Item pivo = v[r];

    for (int i = l; i < r; i++)
        if (less(v[i], pivo))
        {
            exch(v[i], v[j]);
            j++;
        }

    exch(v[j], v[r]);
    return j;
}

void insertionsort(Item *v, int l, int r)
{
    for (int i = r; i > l; i--)
        cmpexch(v[i - 1], v[i]);

    for (int i = l + 2; i <= r; i++)
    {
        int j = i;
        Item m = v[j];
        while (less(m, v[j - 1]))
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = m;
    }
}

static void quicksortM3(Item *V,int l, int r)
{
  if (r-l<=32) return;

  exch(V[(l+r)/2], V[r-1]);
  cmpexch(V[l], V[r-1]);
  cmpexch(V[l], V[r]);
  cmpexch(V[r-1], V[r]);

  int j = separa(V, l+1, r-1);
  quicksortM3(V, l, j-1);
  quicksortM3(V, j+1, r);
}

void quicksort(Item *V,int l,int r)
{
  quicksortM3(V,l,r);
  insertionsort(V,l,r);
}

int main(void)
{
    int r = 0;
    scanf("%d", &r);
    
    Item num[r];
    
    for (int i = 0; i < r; i++)
        scanf("%d", &num[i]);

    quicksort(num, 0, r-1);

    for (int j = 0; j < r; j++)
    {    
        if (j == r-1) 
            printf("%d\n", num[j]);
        else 
            printf("%d ", num[j]);
    }
    return 0;
}