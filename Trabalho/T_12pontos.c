#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Item;

typedef struct no_st
{
    Item e;
    struct no_st *prox;
    struct no_st *ant;
} no;

typedef struct lista
{
    no *inicio;
    no *fim;
    int no_count;
} lista;

void inicializa_lista(lista *l)
{
    l -> inicio = NULL;
    l -> fim = NULL;
    l -> no_count = 0;
}

int insere_fim(lista *l, Item e)
{
    no *novono = malloc(sizeof(no));
    if (novono == NULL) return 0;
    novono -> e = e;
    novono -> prox = NULL;
    novono -> ant = l -> fim;
    if (l -> inicio == NULL) l-> inicio = novono;
    else l -> fim -> prox = novono;
    l -> fim = novono;
    l -> no_count++;
    return 1;
}

int insere_inicio(lista *l, Item e)
{
    no *novono = malloc(sizeof(no));
    if (novono == NULL) return 0;
    novono -> e = e;
    novono -> prox = l -> inicio;
    novono -> ant = NULL;
    if (l -> inicio == NULL)
        l -> fim = novono;
    else
        l -> inicio -> ant = novono;
    l -> inicio = novono;
    l -> no_count++;
    return 1;
}

Item remove_inicio(lista *l)
{
    if (l -> inicio == l -> fim)
    {
        l -> fim = l -> fim -> prox;
    }
    
    no *toremove = l -> inicio;
    Item rtn = toremove -> e;
    l -> inicio = toremove -> prox;
    if (l -> inicio) l -> inicio -> ant = NULL;
    free(toremove);
    l -> no_count--;
    return rtn;
}

Item remove_fim(lista *l)
{
    if (l -> inicio == l -> fim)
    {
        return remove_inicio(l);
    }
    
    no *toremove = l -> fim;
    l -> fim = toremove -> ant;
    l -> fim -> prox = NULL;
    Item rtn = toremove -> e;
    free(toremove);
    l -> no_count--;
    return rtn;
}

int listavazia(lista *l)
{
    return l -> inicio == NULL;
}

int toFront(lista *l, Item e, int reversa)
{
    reversa ? insere_fim(l, e) : insere_inicio(l, e);
}

int push_back(lista *l, Item e, int reversa)
{
    reversa ? insere_inicio(l, e) : insere_fim(l, e);
}

Item front(lista *l, int reversa)
{
    return reversa ? remove_fim(l) : remove_inicio(l);
}

Item back(lista *l, int reversa)
{
    return reversa ? remove_inicio(l) : remove_fim(l);
}

int main(void)
{
    int Q;
    scanf("%d", &Q);
    lista l;
    inicializa_lista(&l);
    int reversa = 0;
    for (int i = 0; i < Q; i++)
    {   
        int n;
        char cmd[12];
        scanf(" %s", cmd);

        if (strcmp(cmd, "reverse") == 0)
        {
            reversa = !reversa;
        }
        
        else if (strcmp(cmd, "back") == 0)
        {
            if (!listavazia(&l))
            {
                printf("%d\n", back(&l, reversa));
            }
            else
            {
                printf("No job for Ada?\n");
            }
        }
        
        else if (strcmp(cmd, "front") == 0)
        {
            if (!listavazia(&l))
            {
                printf("%d\n", front(&l, reversa));
            }
            else
            {
                printf("No job for Ada?\n");
            }
        }
        
        else if (strcmp(cmd, "push_back") == 0)
        {
            scanf("%d", &n);
            push_back(&l, n, reversa);
        }

        else if (strcmp(cmd, "toFront") == 0)
        {
            scanf("%d", &n);
            toFront(&l, n, reversa);
        }
    }
    return 0;
}