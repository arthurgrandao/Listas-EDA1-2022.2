#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define less(A,B) ((A) < (B))
#define exch(A,B) { Item tt; tt = A; A = B; B = tt; }
#define cmpexch(A,B) {if (less(B,A)) exch(A,B)}

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

int main(void)
{
    Item *num = malloc(50000*4);

    int i = 0;
    while(scanf("%d", &num[i]) == 1)
        i++;

    insertionsort(num, 0, i-1);

    for (int j = 0; j < i; j++) 
       printf("%d%s", num[j], j == i - 1 ? "\n" : " ");

    free(num);
}
