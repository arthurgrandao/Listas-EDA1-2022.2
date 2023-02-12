#include <stdio.h>

typedef int Item;

#define less(A,B) ((A) < (B))
#define exch(A,B) { Item tt; tt = A; A = B; B = tt; }

void selectionsort(Item *v, int l, int r)
{
    for (int i = l; i < r; i++)
    {
        int min = i;
        for (int j = i+1; j <= r; j++)
            if (less(v[j], v[min]))
                min = j;
        exch(v[i], v[min]);
    }
}

int main(void)
{
    Item num[1000];

    int i = 0;
    while(scanf("%d", &num[i]) != EOF)
        i++;

    selectionsort(num, 0, i-1);

    for (int j = 0; j < i; j++)
    {    
        if (j == i-1) 
            printf("%d\n", num[j]);
        else 
            printf("%d ", num[j]);
    }
}
