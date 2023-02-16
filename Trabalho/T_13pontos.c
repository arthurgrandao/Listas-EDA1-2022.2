#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Item;

#define TAM_MAX 4194304

typedef struct no_st
{
    Item *e;
    struct no_st *prox;
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

int insere_fim(lista *l, Item *string)
{
    int len_str = strlen(string);
    no *novono = malloc(sizeof(no));
    if (novono == NULL) return 0;
    novono -> e = malloc(len_str*sizeof(char) + 1);
    if (novono->e == NULL) return 0;
    strcpy(novono -> e, string);
    novono -> prox = NULL;
    if (l -> inicio == NULL) l-> inicio = novono;
    else l -> fim -> prox = novono;
    l -> fim = novono;
    l -> no_count++;
    return 1;
}

int comparador(char *str, char *sub)
{
    while (*str != '\0' && *sub != '\0')
    {
        if (*str != *sub)
            return 0;
        str++;
        sub++;
    }

    if (*sub == '\0')
        return 1;

    return 0;
}

int substring_count(char *str, char *sub)
{
    int count = 0;
    int len_sub = strlen(sub);
    while (*str != '\0') 
    {
        if (*str == *sub && comparador(str, sub))
        {
            count++;
            str += len_sub;
        } 
        else 
        {
            str++;
        }
    }

    return count;
}

char string[TAM_MAX];

int main(void)
{
    int len_sub = 0;

    lista l;
    inicializa_lista(&l);

    while (scanf("%s", &string) == 1)
    {
        insere_fim(&l, string);
    }
    
    no *aux = l.inicio;
    no *comp = l.fim;
    while (aux != l.fim)
    {
        printf("%d\n", substring_count(aux->e, comp->e));
        aux = aux-> prox;
    }
}