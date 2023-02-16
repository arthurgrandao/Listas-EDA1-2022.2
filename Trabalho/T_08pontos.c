#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define less(A, B) A < B

typedef struct no_st
{
    Item e;
    struct no_st *prox;
} no;

typedef struct pilha
{
    no *inicio;
    int no_count;
} pilha;


void inicializa_pilha (pilha *p)
{
    p -> inicio = NULL;
    p -> no_count = 0;
}

int empilha (pilha *p, Item e)
{
    no *novono = malloc(sizeof(no));
    if(novono == NULL) return 0;
    novono -> e = e;
    novono -> prox = p -> inicio;
    p -> inicio = novono;
    p -> no_count++;
    return 1;
}

Item desempilha(pilha *p)
{
    no *toremove = p -> inicio;
    p -> inicio = p -> inicio -> prox;
    Item rtn = toremove -> e;
    free(toremove);
    p -> no_count--;
    return rtn;
}

Item topo(pilha *p)
{
    if (p -> inicio == NULL) return ;
    return p -> inicio -> e;
}

int pilhavazia(pilha *p)
{
    return p -> inicio == NULL;
}

int tampilha(pilha *p)
{
    return p -> no_count;
}

void imprime_pilha(pilha *p)
{
    no *aux = p -> inicio;
    while (aux != NULL)
    {
        printf("%d ", aux -> e);
        aux = aux -> prox;
    }
}

typedef struct fila
{
    no *inicio;
    no *fim;
    int no_count;
} fila;

void inicializa_fila(fila *f)
{
    f -> inicio = NULL;
    f -> fim = NULL;
    f -> no_count = 0;
}
int enfileira(fila *f, Item e)
{
    no *novono = malloc(sizeof(no));
    if (novono == NULL) return 0;
    novono -> e = e;
    novono -> prox = NULL;
    if (f -> inicio == NULL) f-> inicio = novono;
    else f -> fim -> prox = novono;
    f -> fim = novono;
    f -> no_count++;
    return 1;
}

Item desinfileira (fila *f)
{
    no *toremove = f -> inicio;
    Item rtn = toremove -> e;
    f -> inicio = f -> inicio -> prox;
    free(toremove);
    f ->no_count--;
    return rtn;
}

Item espia(fila *f)
{
    return f -> inicio -> e;
}

int filavazia(fila *f)
{
    return f -> inicio == NULL;
}

void imprime_fila_contrario(fila *f)
{
    if (filavazia(f)) return;
    Item x = desinfileira(f);
    imprime_fila_contrario(f);
    printf("%d ", x);
}
void imprime_fila(fila *f)
{
    no *aux = f -> inicio;
    while (aux != NULL)
    {
        printf("%d ", aux -> e);
        aux = aux -> prox;
    }
}

int main(void)
{
    int N;
    while (scanf("%d", &N) && N != 0)
    {
        int resultado = 1;
        fila r_p;
        fila p;
        pilha r_a;
        inicializa_fila(&r_p);
        inicializa_fila(&p);
        inicializa_pilha(&r_a);

        for (int i = 0; i < N; i++)
        {
            Item carro;
            scanf("%d", &carro);
            enfileira(&r_p, carro);
        }

        while (!filavazia(&r_p))
        {
            Item mao = desinfileira(&r_p);

            if (!pilhavazia(&r_a))
            {
                while (!pilhavazia(&r_a) && less(topo(&r_a), mao))
                {
                    enfileira(&p, desempilha(&r_a));
                }
                empilha(&r_a, mao);
                continue;
            }

            else if (!filavazia(&r_p) && less(mao, espia(&r_p))) 
            {
                enfileira(&p, mao);
                continue;
            }
            else
                empilha(&r_a, mao);
        }

        while (!pilhavazia(&r_a))
        {
            enfileira(&p, desempilha(&r_a));
        }
        while (!filavazia(&p))
        {
            Item aux = desinfileira(&p);

            if (!filavazia(&p))
            {
                if (less(espia(&p), aux))
                {
                    resultado = 0;
                    break;
                }
            }   
        }

        printf(resultado ? "yes\n" : "no\n");
    }
    return 0;
}