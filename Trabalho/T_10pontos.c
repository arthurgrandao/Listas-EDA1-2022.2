#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define key(A) (A)
#define greater(A,B) (key(A) > key(B))
#define exch(A, B) {Item tt = A; A = B; B = tt;}
#define cmpexch(A, B) {if(greater(B, A)) exch(A, B);}

typedef struct fila_prioridade
{
    Item *heap;
    int N, capacidade;
} pq;

void PQinit(pq *pq, int N)
{
    pq -> capacidade = N;
    pq -> heap = malloc(sizeof(Item) * (N + 1));
    pq -> N = 0;
}

int PQempty(pq *pq)
{
  return pq -> N == 0;
}

void fixDown(pq *pq, int k, int N)
{
  int j;
  while(2*k <= N)
  {
    j=2*k;
    if(j<N && greater(pq -> heap[j],pq -> heap[j+1])) j++;
    if(!greater(pq -> heap[k],pq -> heap[j])) break;
    exch(pq -> heap[k],pq -> heap[j]);
    k=j;
  }
}

void fixUp(pq *pq, int k)
{
  while(k > 1 && greater(pq -> heap[k/2],pq -> heap[k]))
  {
    exch(pq -> heap[k],pq -> heap[k/2]);
    k=k/2;
  }
}

void PQaumenta(pq *pq, int novoTamanho)
{
    if (novoTamanho <= pq -> capacidade)
    {
        return;
    }
    pq -> capacidade *= 4;
    pq -> heap = realloc(pq -> heap, (pq -> capacidade + 1) * sizeof(Item));
    
}

void PQinsert(pq *pq, Item e)
{
    PQaumenta(pq, pq -> N + 1);
    pq -> heap[++pq -> N] = e;
    fixUp(pq, pq -> N);        
}

Item PQdelmin(pq *pq)
{
  exch(pq -> heap[1], pq -> heap[pq -> N]);
  fixDown(pq, 1, --pq -> N);
  return pq -> heap[pq -> N + 1];
}

int main(void)
{
    pq pq;
    PQinit(&pq, 101);
    Item removidos[101];
    int cmd, n;
    while (scanf("%d %d", &cmd, &n) == 2)
    {
        if (cmd == 1)
        {
           PQinsert(&pq, n);
        }
        if (cmd == 2)
        {
            int i_removidos;
            for (i_removidos = 0; i_removidos < n; i_removidos++)
            {
                Item menor = PQdelmin(&pq);
                removidos[i_removidos] = menor;               
            } 

            for (int i = 0; i < i_removidos; i++)
            {
                printf(i != n - 1 ? "%d " : "%d\n", removidos[i]);
                PQinsert(&pq, removidos[i]);
            }       
        }   
    }
    return 0;
}