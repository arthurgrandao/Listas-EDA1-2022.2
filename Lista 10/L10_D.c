#include <stdio.h>

typedef int Item;

#define less(A,B) ((A) < (B))
#define eq(A,B) ((A) == (B))
#define exch(A,B) { Item tt; tt = A; A = B; B = tt; }

int bb(Item *v, int l, int r, int b)
{
    if (r<l)
        return (l+r+1)/2;
    
    int meio = (l+r)/2;
    
    if (eq(b,v[meio]))
        return meio;
    
    else if (less(b,v[meio]))
        return bb(v, l, meio-1, b);
    
    else if (less(v[meio], b))
        return bb(v, meio+1, r, b);
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    Item vetor[n];
    Item busca;

    for (int i = 0; i < n; i++)
        scanf("%d", &vetor[i]);
    
    for (int i = 0; i < m; i++)
    {    
        scanf("%d", &busca);
        printf("%d\n",bb(vetor, 0, n-1, busca));
    }
    
    return 0;
}