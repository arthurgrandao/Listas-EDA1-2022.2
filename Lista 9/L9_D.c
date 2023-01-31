#include <stdio.h>

typedef struct{
    int valor;
    int posicao;
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
            if (less(v[j].valor, v[min].valor))
                min = j;
        exch(v[i], v[min]);
    }
}

int bb(Item *v, int l, int r, int b)
{
    if (r<l)
        return -1;
    
    int meio = (l+r)/2;
    
    if (eq(b,v[meio].valor))
        return v[meio].posicao;
    
    else if (less(b,v[meio].valor))
        return bb(v, l, meio-1, b);
    
    else if (less(v[meio].valor, b))
        return bb(v, meio+1, r, b);
}

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);

    Item vetor[m]; 
    int valores[n];

    for (int i = 0; i < m; i++)
    {
        Item temp;
        scanf("%d", &temp.valor);
        temp.posicao = i;
        vetor[i] = temp;
    }    
    for (int j = 0; j < n; j++)
        scanf("%d", &valores[j]);

    selectionsort(vetor, 0, m-1);

    for (int k = 0; k < n; k++)
        printf("%d\n", bb(vetor, 0, m-1, valores[k]));
}
