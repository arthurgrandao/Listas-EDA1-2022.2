#include <stdio.h>

typedef struct{
    int codigo;
    char comando[15];
} Item;

#define less(A,B) ((A) < (B))
#define eq(A,B) ((A) == (B))
#define exch(A,B) { Item tt; tt = A; A = B; B = tt; }


void selectionsort(Item *v, int l, int r)
{
    for (int i = l; i < r; i++)
    {
        int min = i;
        for (int j = i+1; j <= r; j++)
            if (less(v[j].codigo, v[min].codigo))
                min = j;
        exch(v[i], v[min]);
    }
}

char *bb(Item *v, int l, int r, int b)
{
    if (r<l)
        return "undefined";
    
    int meio = (l+r)/2;

    if (eq(b, v[meio].codigo))
        return v[meio].comando;

    else if (less(b, v[meio].codigo))
        return bb(v, l, meio - 1, b);

    else if (less(v[meio].codigo, b))
        return bb(v, meio + 1, r, b);
}

int main(void)
{
    int n;
    scanf("%d", &n);

    Item comandos[n];

    for (int i = 0; i < n; i++)
    {
        Item temp;
        scanf("%d %s", &temp.codigo, &temp.comando);
        comandos[i] = temp;
    }

    selectionsort(comandos, 0, n-1);

    int comp;
    while (scanf("%d", &comp) == 1)
        printf("%s\n", bb(comandos, 0, n-1, comp));
}
