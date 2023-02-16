#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct pista
{
    Item id, valor, idp;
} pista;

typedef struct no_st
{
    // Item id, valor, idp;
    pista p;
    struct no_st *prox;
} no;

typedef struct cabeca
{
    no *inicio;
    int no_count;
    no *fim;
} head;


void inicializa_lista (head *h)
{
    h -> inicio = NULL;
    h -> fim = NULL;
    h -> no_count = 0;
}

int insere_inicio(head *h, pista p)
{
    no *novono = malloc(sizeof(no));
    if(novono == NULL) return 0;
    novono -> p = p;
    novono -> prox = h -> inicio;
    h -> inicio = novono;
    if (h -> fim == NULL) 
        h -> fim = novono;
    h -> no_count++;
    return 1;
}

int insere_fim(head *h, pista p)
{
    no *novono = malloc(sizeof(no));
    if(novono == NULL) return 0;
    novono -> p = p;
    novono -> prox = NULL;
    if (h -> inicio == NULL) h-> inicio = novono;
    else h -> fim -> prox = novono;
    h -> fim = novono;
    h -> no_count++;
    return 1;
}

void remove_inicio(head *h)
{
    no *toremove = h -> inicio;
    h -> inicio = h -> inicio -> prox;
    free(toremove);
    h -> no_count--;
}

void printa_pistas_ordenadas(head *h)
{
    no* aux = h -> inicio;
    while (aux -> p.idp != -1)
    {
        printf("%d\n", aux ->p.valor);
        no *tmp = h -> inicio;
        while (tmp -> p.id != aux -> p.idp)
        {
            tmp = tmp -> prox;
        }
        aux = tmp;
    }
    printf("%d\n", aux ->p.valor);
}

int main(void)
{
    int N;
    scanf("%d", &N);
    head h;
    inicializa_lista(&h);
    Item id, valor, idp;
    for (int i = 0; i < N; i++)
    {    
        scanf("%d %d %d", &id, &valor, &idp);
        pista p = {id, valor, idp};
        insere_fim(&h, p);
    }
    printa_pistas_ordenadas(&h);
    return 0;
}