#include <stdio.h>;
#include <stdlib.h>;
#include <string.h>;

typedef char Item;

typedef struct no_st
{
    Item e[101];
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

int empilha (pilha *p, Item *e)
{
    no *novono = malloc(sizeof(no));
    if(novono == NULL) return 0;
    strcpy(novono -> e, e);
    novono -> prox = p -> inicio;
    p -> inicio = novono;
    p -> no_count++;
    return 1;
}

void desempilha(pilha *p)
{
    no *toremove = p -> inicio;
    p -> inicio = p -> inicio -> prox;
    free(toremove);
    p -> no_count--;
}

Item* topo(pilha *p)
{
    if (p -> inicio == NULL) return NULL;
    return p -> inicio -> e;
}

int pilhavazia(pilha *p)
{
    return p -> inicio == NULL;
}

void imprime_pilha(pilha *p)
{
    no *aux = p -> inicio;
    while (aux != NULL)
    {
        printf("%s ", aux -> e);
        aux = aux -> prox;
    }
}


int main(void)
{
    char cmd[9];
    pilha p;
    inicializa_pilha(&p);
    while (scanf(" %s", cmd) == 1)
    {
        if (strcmp(cmd,"desfazer") == 0)
        {
            if (pilhavazia(&p))
            {
                printf("NULL\n");
            }
            else
            {
                printf("%s\n", topo(&p));
                desempilha(&p);
            }                         
        }        
        else
        {
            char txt[101];
            getchar();
            scanf("%[^\n]", txt);
            empilha(&p, txt);
        }
    }
  
    return 0;
}
