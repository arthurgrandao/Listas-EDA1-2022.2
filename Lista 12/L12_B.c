#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int tamanho;
    char pe;
} Item;

struct fila_st
{
    Item *v;
    int size;
    int inicio;
    int fim;
    int ocupados;
};

int inicializafila(struct fila_st *f, int s)
{
    f->v = malloc(sizeof(Item) * s);
    f->size = s;
    f->inicio = -1;
    f->fim = 0;
    f->ocupados = 0;
    return 1;
}

int enfila(struct fila_st *f, Item e)
{
    if (f->ocupados >= f->size) return 0;
    f->v[f->fim] = e;
    f->fim = (f->fim + 1) % f->size;
    f->ocupados++;
    return 1;
}

void desenfila(struct fila_st *f)
{
    f->ocupados--;
    f->inicio = (f->inicio + 1) % f->size;
}

Item espia(struct fila_st *f)
{
    return f->v[(f->inicio + 1) % f->size];
}

int esta_vazia(struct fila_st *f)
{
    return f->ocupados == 0;
}

void liberafila(struct fila_st *f)
{
    free(f->v);
    f->size = 0;
}


int main(void)
{
    int n;
    int tamanho;
    char pe;
    int pares = 0;

    while (scanf(" %d", &n) == 1)
    {   
        struct fila_st fila;
        struct fila_st aux;
        inicializafila(&fila, n);
        inicializafila(&aux, n);
        
        for (int i = 0; i < n; i++)
        {
            Item add;
            scanf("%d %c", &add.tamanho, &add.pe);
            
            if (esta_vazia(&fila))
            {
                enfila(&fila, add);
                continue;
            }
            
            int p_antes = pares;
            while (!esta_vazia(&fila))
            {
                Item x = espia(&fila);
                if (add.tamanho == x.tamanho)
                    if (add.pe == (char) x.pe-1 || add.pe == (char) x.pe+1)
                    {
                        desenfila(&fila);
                        pares++;
                        break;
                    }
                enfila(&aux, x);
                desenfila(&fila);
            }

            if (p_antes == pares) enfila(&aux, add);
            while (!esta_vazia(&aux))
            {
                Item l = espia(&aux);
                enfila(&fila, l);
                desenfila(&aux);
            }

        }
        printf("%d\n", pares);
        pares = 0;
        
        liberafila(&aux);
        liberafila(&fila);    
    }
}