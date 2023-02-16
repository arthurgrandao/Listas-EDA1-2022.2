#include <stdio.h>
#include <stdlib.h>

typedef char Item;

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

void desempilha(pilha *p)
{
    no *toremove = p -> inicio;
    p -> inicio = p -> inicio -> prox;
    free(toremove);
    p -> no_count--;
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
        printf("%c ", aux -> e);
        aux = aux -> prox;
    }
    printf("\n");
}

void estaequilibrada(char *string, pilha *p)
{
    int i = 0;
    while (string[i] != '\0')
    {
        if (!pilhavazia(p))
        {
            Item top = topo(p);

            if ((string[i] == '*' && top == '*') || (string[i] == '/' && top == '/') || (string[i] == '_' && top == '_'))
            {
                desempilha(p);
                i++;
                continue;
            }  
        }
        
        if (string[i] == '*' || string[i] == '/' || string[i] == '_')
        {
            empilha(p, string[i]);
            i++;
            continue;
        }
        i++;
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);
    
    int resposta = 0;
    
    pilha p;
    inicializa_pilha(&p);

    for (int i = 0; i < N; i++)
    {
        char linha[100001];
        getchar();
        scanf("%[^\n]", linha);

        estaequilibrada(linha, &p);       
    }
    printf(pilhavazia(&p) ? "C\n" : "E\n");
    return 0;
}