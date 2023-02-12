#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char japones[81];
    char traducao[81];
} Item;

#define Key(A) (A.japones)
#define less(A,B) (strcmp(Key(A), Key(B)) < 0)
#define exch(A,B) { Item tt; tt = A; A = B; B = tt; }
#define cmpexch(A,B) {if (less(B, A)) exch(A,B)}


int separa(Item *v, int l, int r)
{
    Item pivo = v[r];
    int j = l;
    for (int k = l; k < r; k++)
        if (less(v[k], pivo))
        {
            exch(v[k], v[j]);
            j++;
        }
    exch(v[j], v[r]);
    return j;
}

void quicksortM3(Item *v, int l, int r)
{
    if (r - l <= 32)
        return;

    exch(v[(l + r) / 2], v[r - 1]);
    cmpexch(v[l], v[r - 1]);
    cmpexch(v[l], v[r]);
    cmpexch(v[r - 1], v[r]);

    int m = separa(v, l, r);
    quicksortM3(v, l, m - 1);
    quicksortM3(v, m + 1, r);
}

void insertionsort(Item *v, int l, int r)
{
    for (int i = l + 1, j; i <= r; i++)
    {
        Item t = v[i];
        for (j = i; j > 0 && less(t, v[j - 1]); j--)
            v[j] = v[j - 1];
        v[j] = t;
    }
}

void quicksort(Item *v, int l, int r)
{
    quicksortM3(v, l, r);
    insertionsort(v, l, r);
}

char *bb(Item *v, int l, int r, char *b)
{
    if (r<l)
        return b;
    
    int meio = (l+r)/2;
    
    if (strcmp(b, v[meio].japones) == 0)
        return v[meio].traducao;
    
    else if (strcmp(b, v[meio].japones) < 0)
        return bb(v, l, meio-1, b);
    
    else if (strcmp(b, v[meio].japones) > 0)
        return bb(v, meio+1, r, b);
}


int main(void)
{
    int n_instancias = 0;
    scanf("%d", &n_instancias);

    for (int i = 0; i < n_instancias; i++)
    {
        int n_palavras = 0, n_linhas = 0;
        scanf("%d %d", &n_palavras, &n_linhas);

        Item dicionario[n_palavras];
        for (int j = 0; j < n_palavras; j++)
        {
            scanf("%s", dicionario[j].japones); 
            scanf(" %[^\n]", dicionario[j].traducao);
        }

        quicksort(dicionario, 0, n_palavras-1);

        for (int k = 0; k < n_linhas; k++)
        {
            char musica[80];
            
            getchar();
            scanf("%[^\n]", musica);
            
            char *token = strtok(musica, " ");

            while (token != NULL)
            {
               printf("%s ", bb(dicionario, 0, n_palavras-1, token));
               token = strtok(NULL, " "); 
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}