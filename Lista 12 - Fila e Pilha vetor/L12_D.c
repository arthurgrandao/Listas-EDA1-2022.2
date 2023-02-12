#include <stdio.h>
#include <stdlib.h>

typedef char Item;

typedef struct pilha_st
{
    Item *v;
    int topo, size;
} pilha_st;

int incializa_p(struct pilha_st *p, int s)
{
    p->v = malloc(sizeof(Item)*s);
    if (p->v == NULL) return 0;
    p->size = s;
    p->topo = 0;
    return 1;
}

int empilha(struct pilha_st *p, Item e)
{
    if (p->size == p->topo) return 0;
    p->v[p->topo++] = e;
    return 1;
}

void desempilha(struct pilha_st *p)
{
    p->topo--;
}

int vazia_p(struct pilha_st *p)
{
    return p->topo == 0;
}

Item topo(struct pilha_st *p)
{
    return p->v[p->topo-1]; 
}

char bem_formada(char *string, int size)
{
    struct pilha_st p;
    incializa_p(&p, size); // O tamanho nao foi informado no enunciado.

    int aux = 0;
    while (string[aux] != '\n')
    {
        if (string[aux] == '{' || string[aux] == '[' || string[aux] == '(')
            empilha(&p, string[aux]);
        else
        {
            if (string[aux] == '}' && topo(&p) != '{') return 'N';
            else if ((string[aux] == ']' && topo(&p) != '[')) return 'N';
            else if ((string[aux] == ')' && topo(&p) != '(')) return 'N';
            else desempilha(&p);
        } 
        aux++;
    }
    if (vazia_p(&p)) return 'S';
    free((&p)->v);
}

int main(void)
{
    char *string = malloc(100000*sizeof(char));
    size_t tambuff = 100000;
    int count = 0; 
    int size = 0;

    scanf("%d", &count);
    getchar();
    for (size_t i = 0; i < count; i++)
    {
        size = getline(&string, &tambuff, stdin);
        printf("%c\n", bem_formada(string, size));
    }
    free(string);
}