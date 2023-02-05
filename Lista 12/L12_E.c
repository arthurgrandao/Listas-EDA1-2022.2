#include <stdio.h>
#include <stdlib.h>

typedef int Item;

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
    if (f->ocupados >= f->size)
        return 0;
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

int resta1 (struct fila_st *f)
{
    return f->ocupados == 1;
}

void liberafila(struct fila_st *f)
{
    free(f->v);
    f->size = 0;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    
    struct fila_st f;
    struct fila_st d;
    inicializafila(&f, n);
    inicializafila(&d, n-1);
    for (size_t i = 1; i <= n; i++)
        enfila(&f, i);
    
    Item descartado;
    while (!resta1(&f))
    {
        descartado = espia(&f);
        desenfila(&f);
        enfila(&f, espia(&f));
        desenfila(&f);
        enfila(&d, descartado);
    }
    
    printf("Cartas descartadas: ");
    while (!esta_vazia(&d))
    {
        printf("%d", espia(&d));
        desenfila(&d);
        (!esta_vazia(&d)) ?  printf(", ") : printf("\n");
    }
    
    printf("Carta restante: %d\n", espia(&f));

    liberafila(&d), liberafila(&f);
}
