#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int codigo;
    int votos;
} Item;

#define codigo(A) (A.codigo)
#define votos(A) (A.votos)
#define less(A,B) ((votos(A) == votos(B)) ? (codigo(A) > codigo(B)) : (votos(A) > votos(B))) //(votos(A) > votos(B)) 
#define exch(A,B) { Item tt; tt = A; A = B; B = tt; }
#define cmpexch(A,B) {if (less(B,A)) exch(A,B)}


int separa(Item *v, int l, int r)
{
    Item pivo = v[r];
    int j = l;
    for (int k = l; k < r; k++)
        if (less(v[k], pivo))
        {
            exch(v[k], v[j]);
            j++;
        }
    exch(v[j], v[r]);
    return j;
}

void quicksortM3(Item *v, int l, int r)
{
    if (r - l <= 16)
        return;

    exch(v[(l + r) / 2], v[r - 1]);
    cmpexch(v[l], v[r - 1]);
    cmpexch(v[l], v[r]);
    cmpexch(v[r - 1], v[r]);

    int m = separa(v, l, r);
    quicksortM3(v, l, m - 1);
    quicksortM3(v, m + 1, r);
}

void insertionsort(Item *v, int l, int r)
{
    for (int i = r; i > l; i--)
        cmpexch(v[i - 1], v[i]);

    for (int i = l + 2; i <= r; i++)
    {
        int j = i;
        Item m = v[j];
        while (less(m, v[j - 1]))
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = m;
    }
}

void quicksort(Item *v, int l, int r)
{
    quicksortM3(v, l, r);
    insertionsort(v, l, r);
}


int main(void)
{
    int sen, depf, depe;
    scanf("%d %d %d", &sen, &depf, &depe);
    
    int candidato;

    Item *presidente = calloc(100, sizeof(Item)), 
         *senador = calloc(1000, sizeof(Item)), 
         *deputadof = calloc(10000, sizeof(Item)), 
         *deputadoe = calloc(100000, sizeof(Item));
    
    int validos = 0, invalidos = 0;
    int total_pres = 0;

    while (scanf("%d", &candidato) == 1)
    {
        if (candidato > 0)
        {
            validos++;

            if (candidato >= 10000)
            {
                if (deputadoe[candidato].codigo == 0) deputadoe[candidato].codigo = candidato; 
                deputadoe[candidato].votos++;
            }
            else if (candidato >= 1000)
            {
                if (deputadof[candidato].codigo == 0) deputadof[candidato].codigo = candidato; 
                deputadof[candidato].votos++;
            }

            else if (candidato >= 100)
            {
                if (senador[candidato].codigo == 0) senador[candidato].codigo = candidato; 
                senador[candidato].votos++;
            }
            else
            {
                if (presidente[candidato].codigo == 0) presidente[candidato].codigo = candidato;
                presidente[candidato].votos++;
                total_pres++;
            }
        }
        else
            invalidos++;
    }

    int aux = 0;
    for (int i = 0; i < 100; i++)
        if (presidente[i].votos)
            presidente[aux++] = presidente[i];
    quicksort(presidente, 0, aux);
    
    aux = 0;
    for (int i = 0; i < 1000; i++)
        if (senador[i].votos)
            senador[aux++] = senador[i];
    quicksort(senador, 0, aux);
    
    aux = 0;
    for (int i = 0; i < 10000; i++)
        if (deputadof[i].votos)
            deputadof[aux++] = deputadof[i];
    quicksort(deputadof, 0, aux);
    
    aux = 0;
    for (int i = 0; i < 100000; i++)
        if (deputadoe[i].votos)
            deputadoe[aux++] = deputadoe[i];
    quicksort(deputadoe, 0, aux);

    printf("%d %d\n", validos, invalidos);

    if ((float) presidente[0].votos/total_pres >= 0.51)
        printf("%d\n", presidente[0].codigo);
    else
        printf("Segundo turno\n");
    
    for (int i = 0; i < sen; i++)
        printf("%d ", senador[i].codigo);   
    printf("\n");

    for (int i = 0; i < depf; i++)
        printf("%d ", deputadof[i].codigo);   
    printf("\n");

    for (int i = 0; i < depe; i++)
        printf("%d ", deputadoe[i].codigo);   
    printf("\n");
    
    free(presidente);
    free(senador);
    free(deputadof);
    free(deputadoe);

    return 0;
}