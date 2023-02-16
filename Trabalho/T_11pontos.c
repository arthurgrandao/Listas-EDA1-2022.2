#include <stdio.h>
#include <stdlib.h>

#define posvalida(x, y) ((x >= 0 && x < N ) && (y >= 0 && y < M))

typedef struct pos
{
    int x, y;
}pos;

typedef struct celula
{
    char tipo;
    int altura;

} cel;


// void inicializa_campo(char **campo, int N, int M)
// {
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < M; j++)
//         {
//             /* code */
//         }
        
//     }
    
// }


//     printf("Matriz:\n");
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < M; j++)
//         {
//             printf("i: %d\tj:%d\n", i, j);
//             printf("%c", campo[i][j].tipo);
//         }
//         printf("\n");

// printf("Matriz:\n");
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < M; j++)
//         {   
//             if (campo[i][j].tipo == 't')
//                 printf("%d", campo[i][j].altura);
//             else    
//                 printf("%c", campo[i][j].tipo);
//         }
//         printf("\n");
//     }

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    cel campo[N][M];

    pos *pos_torres = calloc(M * N, sizeof(pos));
    int qtd_torres = 0;
    for (int i = 0; i < N; i++)
    {
        getchar();
        for (int j = 0; j < M; j++)
        {
            scanf("%c", &campo[i][j].tipo);
            campo[i][j].altura = 0;
            if (campo[i][j].tipo == 't')
                {
                    pos torre = {i, j};
                    pos_torres[qtd_torres++] = torre;
                }
        }  
              
    }

    for (int i = 0; i < qtd_torres; i++)
    {
        pos torre = pos_torres[i];
        scanf("%d", &campo[torre.x][torre.y].altura);      
    }

    int cont = 0;

    for(int k = 0; k < qtd_torres; k++)
    {   
        int x = pos_torres[k].x;
        int y = pos_torres[k].y;
        for(int i = x - campo[x][y].altura; i <= x + campo[x][y].altura;i++)
        {
            for(int j = y - campo[x][y].altura; j <= y + campo[x][y].altura;j++)
            {
                
                if(!posvalida(i,j)) continue;
                if (campo[i][j].tipo == '#')
                {
                    cont++;
                    campo[i][j].tipo = '.';
                }
            }
        }
    }

    printf("%d\n", cont);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%c", campo[i][j].tipo);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}