/*
 *   José Juntado, um nobre programador também conhecido por JJ, está implementando um sistema que precisa intercalar duas listas simplesmente encadeadas já ordenadas. 
 *   A dificuldade que JJ está enfrentando é que as listas encadeadas podem vir ordenadas de duas maneiras: Não decrescente ou não crescente. 
 *   O resultado final que JJ precisa obter é uma lista, simplesmente encadeada, com os elementos ordenados de maneira não decrescente. 
 *   Você pode assumir que lista encadeada possui a seguinte estrutura para o nó:
 *   
 *   1 typedef struct no_st {
 *   2     Item e;
 *   3     no_st *prox;
 *   4 } no_st;
 *   
 *   Você também pode assumir que as macros less (A,B), lesseq (A,B), equal (A, B), existem e fazem a comparação entre as chaves de uma struct do tipo Item.
 *   O seu objetivo é escrever a função mergelistas que recebe como argumento duas listas encadeadas ordenadas (de maneira não crescente ou não decrescente) 
 *   e devolver uma ponteiro para uma nova lista encadeada contendo uma única lista encadeada ordenada de maneira não decrescente ATENÇÃO a sua função não 
 *   poderá alocar novos nós, deverá apenas rearranjar os elementos para esta nova lista. O protótipo da função que você deve implementar é:
 *   
 *   no_st *mergelistas (no_st *lista1, no st *lista2)
 *   
 *   Abaixo há um exemplo de possíveis listas que podem ser passadas como argumento para a sua função;
 *   
 *   Lista1 -> 23 -> 21 -> 11 -> 9 -> 8 -> 6 -> 4 -> 2 -> NULL
 *   Lista2 -> 1 -> 5 -> 10 -> 15 -> 20 -> 25 -> NULL
 */

#include <stdio.h>
#include <stdlib.h>

#define Key(A) (A->e)
#define less(A,B) (Key(A) < Key(B))
#define equal(A,B) (Key(A) == Key(B))
#define lesseq(A,B) (Key(A) <= Key(B))

typedef int Item;

typedef struct no_st
{
    Item e;
    struct no_st *prox;
} no_st;

typedef struct head_st
{
    no_st *inicio;
    int no_count;
    no_st *fim;
} head_st;

int insere_fim(head_st *h, int valor)
{
    no_st *novono = malloc(sizeof(no_st));
    if(novono == NULL) return 0;
    novono->e = valor;
    novono->prox = NULL;
    if (h->inicio == NULL) h-> inicio = novono;
    else h->fim->prox = novono;
    h->fim = novono;
    h->no_count++;
    return 1;
}

void liberalista(no_st *no)
{
    if (no == NULL) return;

    liberalista(no->prox);
    free(no);
}

void printlista(no_st *no)
{
    if (no == NULL) 
    {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", no->e);
    printlista(no->prox);
}

// Funções implementadas para a resolução
int ehinvertida(no_st *no)
{
    if (no->prox == NULL) return 0;
    if (!lesseq(no, no->prox)) return 1;
    else ehinvertida(no->prox);
}

no_st *invertelista(no_st *a, no_st *b)
{
    if(!b) return a;
    no_st *c = b->prox;
    b->prox = a;
    return invertelista(b, c);
}

no_st *mergelistas(no_st *davez, no_st *outro)
{
    if (davez == NULL || outro == NULL) return davez;

    if (davez->prox != NULL && lesseq(davez->prox, outro))
        mergelistas(davez->prox, outro);
    else
    {
        no_st *c = davez->prox;
        davez->prox = outro;
        mergelistas(outro, c);
    }
    return davez;
}

int main(void)
{
    // Criação das listas de exemplo
    int lista1[8] = {23, 21, 11, 9, 8, 6, 4, 2};
    int lista2[6] = {1, 5, 10, 15, 20, 25};
    head_st *cabeca1 = calloc(1, sizeof(head_st));
    head_st *cabeca2 = calloc(1, sizeof(head_st));
    
    for (int i = 0; i < 8; i++)
    {
        insere_fim(cabeca1, lista1[i]);
        if (i < 6) insere_fim(cabeca2, lista2[i]);
    }

    // Resolução
    if (ehinvertida(cabeca1->inicio)) cabeca1->inicio = invertelista(NULL, cabeca1->inicio);
    if (ehinvertida(cabeca2->inicio)) cabeca2->inicio = invertelista(NULL, cabeca2->inicio);
    
    printf("Lista1 -> ");printlista(cabeca1->inicio);
    printf("Lista2 -> ");printlista(cabeca2->inicio);

    no_st *cabeca3 = NULL;

    if (lesseq(cabeca1->inicio, cabeca2->inicio)) cabeca3 = mergelistas(cabeca1->inicio, cabeca2->inicio);
    else cabeca3 = mergelistas(cabeca2->inicio, cabeca1->inicio);

    printf("ListaO -> ");printlista(cabeca3);
    liberalista(cabeca3);
    
    free(cabeca1); free(cabeca2);
    return 0;
}

