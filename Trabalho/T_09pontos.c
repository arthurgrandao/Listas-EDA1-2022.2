#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Item;

typedef struct no_st
{
    Item e[27];
    struct no_st *prox;
} no;

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
int enfileira(fila *f, Item *e)
{
    no *novono = malloc(sizeof(no));
    if (novono == NULL) return 0;
    strcpy(novono -> e, e);
    novono -> prox = NULL;
    if (f -> inicio == NULL) f-> inicio = novono;
    else f -> fim -> prox = novono;
    f -> fim = novono;
    f -> no_count++;
    return 1;
}

void desinfileira (fila *f)
{
    no *toremove = f -> inicio;
    f -> inicio = f -> inicio -> prox;
    free(toremove);
    f ->no_count--;
}

Item* espia(fila *f)
{
    return f -> inicio -> e;
}

int filavazia(fila *f)
{
    return f -> inicio == NULL;
}

void imprime_fila(fila *f)
{
    no *aux = f -> inicio;
    while (aux != NULL)
    {
        printf("%s\n", aux -> e);
        aux = aux -> prox;
    }
}

int main(void)
{
    fila cidades;
    inicializa_fila(&cidades);
    char cidade[27];

    while (scanf("%s", cidade) == 1)
    {
        enfileira(&cidades, cidade);
    }

    int fim_da_fila = 1;

    while (!filavazia(&cidades))
    {
        char show[27];

        if (fim_da_fila)
        {
            strcpy(show, espia(&cidades));
            desinfileira(&cidades);
            printf("%s\n", show);
        }

        int i = strlen(show) - 1;

        if(!filavazia(&cidades))
        {
            char aux[27];
            strcpy(aux, espia(&cidades));
            desinfileira(&cidades);
    
            if (show[i] == aux[0] + 32)
            {
                enfileira(&cidades, aux);
                fim_da_fila = 1;
            }
            else
            {
                strcpy(show, aux);
                printf("%s\n", show);
                fim_da_fila = 0;
            }     
        }
    }

    return 0;
}