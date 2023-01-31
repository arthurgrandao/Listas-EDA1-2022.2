#include <stdio.h>

typedef struct
{
    int tamanho;
    char caractere;
    int inicio;
} Item;

#define Key(A) ((A).tamanho)
#define less(A,B) (Key(A) < Key(B))
#define lesseq(A,B) (Key(A)<=Key(B))

int tamanho(char *str)
{   
    if (*(str) == '\0') return 0;

    if (*str == *(str+1))
        return 1 + tamanho(str+1);
    else
        return 1;
}       

int x(char *str, Item *resultado, int indice, int n_r)
{
    if (str[indice] == '\0') return n_r;

    Item tmp;
    tmp.inicio = indice;
    tmp.caractere = str[indice];
    tmp.tamanho = tamanho(str+indice);

    *resultado = tmp;

    x(str, resultado+1, indice+tmp.tamanho, n_r+1);
}

void merge(Item *v, int l, int m, int r)
{
    Item *aux = malloc(sizeof(Item) * (r - l + 1));
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r)
    {
        if (lesseq(v[j], v[i]))
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
    char str[100000];
    scanf("%s", str);

    Item resultados[100000];

    int n_r = x(str, resultados, 0, 0);

    mergesort(resultados, 0 , n_r-1);

    for (int i = 0; i < n_r; i++)
        printf("%d %c %d\n", resultados[i].tamanho, resultados[i].caractere, resultados[i].inicio);
}