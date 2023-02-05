#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int codigo;
    int valor;
}Item;

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
    int p, r, count = 1;
    while (scanf("%d %d", &p, &r) && (r != 0 && p != 0))
    {
        struct fila_st fila;
        inicializafila(&fila, p);

        for (size_t i = 0; i < p; i++)
        {
            int codigo;
            scanf("%d", &codigo);
            enfila(&fila, (Item) {codigo, 0});
        }

        int comando;
        for (size_t i = 0; i < r; i++)
        {
            scanf("%*d %d", &comando);

            struct fila_st aux;
            inicializafila(&aux, (&fila)->ocupados);
                        
            while (!esta_vazia(&fila))
            {
                Item x = espia(&fila);
                scanf(" %d", &((&x)->valor));
                if ((&x)->valor == comando)
                    enfila(&aux, x);
                desenfila(&fila);
            }

            while (!esta_vazia(&aux))
            {
                Item y = espia(&aux);
                enfila(&fila, y);
                desenfila(&aux);
            }
            
            liberafila(&aux);
        }
        Item vencedor = espia(&fila);
        printf("Teste %d\n%d\n\n", count, vencedor.codigo);
        liberafila(&fila);
        count++;
    }
}
