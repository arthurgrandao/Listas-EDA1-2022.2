#include <stdio.h>

typedef int Item;

#define less(A,B) ((A) < (B))
#define exch(A, B) { Item tt; tt = A; A = B; B = tt; }

void bubblesort(Item *v, int l, int r)
{
    for (int i = l; i < r; i++)
        for (int j = l; j < r; j++)
            if (less(v[j+1], v[j]))
                exch(v[j+1], v[j]);
}

int main(void)
{
    Item num[1000];

    int i = 0;
    while(scanf("%d", &num[i]) != EOF)
        i++;

    bubblesort(num, 0, i-1);

    for (int j = 0; j < i; j++)
    {    
        if (j == i-1) 
            printf("%d\n", num[j]);
        else 
            printf("%d ", num[j]);
    }
}
