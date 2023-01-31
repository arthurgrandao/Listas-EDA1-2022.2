#include <stdio.h>
#include <string.h>

int main(void)
{
    int L, G;
    scanf("%d", &L);
    scanf("%d", &G);
    int galhosLinhas[G];
    char galhosLados[G];
    for (int i = 0; i < G; i++)
        scanf("%s  %d", &galhosLados[i], &galhosLinhas[i]);

    char ladoInicial, posL;
    scanf(" %c", &ladoInicial);
    char C[2000];
    scanf("%s", C);
    char matriz[5 + L][11];
    for (int i = 0; i < L + 5; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (i < 5)
            {
                matriz[i][j] = ' ';
                continue;
            }
            if (j == 4 || j == 5 || j == 6)
                matriz[i][j] = '|';
            else
                matriz[i][j] = ' ';
        }
    }
    int linhaL = L + 4;
    if (ladoInicial == 'E')
    {
        matriz[linhaL - 1][2] = 'L';
        matriz[linhaL][2] = 'L';
        posL = 'E';
    }
    else
    {
        matriz[linhaL - 1][8] = 'L';
        matriz[linhaL][8] = 'L';
        posL = 'D';
    }
    for (int i = 0; i < G; i++)
    {
        if (galhosLados[i] == 'E')
        {
            matriz[(L + 5) - galhosLinhas[i]][1] = '-';
            matriz[(L + 5) - galhosLinhas[i]][2] = '-';
            matriz[(L + 5) - galhosLinhas[i]][3] = '-';
        }
        else
        {
            matriz[(L + 5) - galhosLinhas[i]][7] = '-';
            matriz[(L + 5) - galhosLinhas[i]][8] = '-';
            matriz[(L + 5) - galhosLinhas[i]][9] = '-';
        }
    }

    printf("~~~~~~~~~~~\n");
    for (int i = L; i < (L + 5); i++)
    {
        for (int j = 0; j < 11; j++)
            printf("%c", matriz[i][j]);
        printf("\n");
    }
    printf("~~~~~~~~~~~\n");

    for (int i = 0; i < strlen(C); i++)
    {
        if (C[i] == 'T' && posL == 'E')
        {
            if (matriz[linhaL - 1][8] == '-' || matriz[linhaL][8] == '-')
            {
                printf("**beep**\n");
                continue;
            }
            matriz[linhaL - 1][2] = ' ';
            matriz[linhaL][2] = ' ';
            matriz[linhaL - 1][8] = 'L';
            matriz[linhaL][8] = 'L';
            posL = 'D';
            printf("~~~~~~~~~~~\n");
            for (int i = L; i < (L + 5); i++)
            {
                for (int j = 0; j < 11; j++)
                    printf("%c", matriz[i][j]);
                printf("\n");
            }
            printf("~~~~~~~~~~~\n");
            continue;
        }

        if (C[i] == 'T' && posL == 'D')
        {
            if (matriz[linhaL - 1][2] == '-' || matriz[linhaL][2] == '-')
            {
                printf("**beep**\n");
                continue;
            }
            matriz[linhaL - 1][8] = ' ';
            matriz[linhaL][8] = ' ';
            matriz[linhaL - 1][2] = 'L';
            matriz[linhaL][2] = 'L';
            posL = 'E';
            printf("~~~~~~~~~~~\n");
            for (int i = L; i < (L + 5); i++)
            {
                for (int j = 0; j < 11; j++)
                    printf("%c", matriz[i][j]);
                printf("\n");
            }
            printf("~~~~~~~~~~~\n");
            continue;
        }

        if (C[i] == 'B' && posL == 'E')
        {
            if (matriz[linhaL][4] == '|')
            {
                matriz[linhaL][4] = '>';
                printf("~~~~~~~~~~~\n");
                for (int i = L; i < (L + 5); i++)
                {
                    for (int j = 0; j < 11; j++)
                        printf("%c", matriz[i][j]);
                    printf("\n");
                }
                printf("~~~~~~~~~~~\n");
                continue;
            }
            else
            {
                matriz[linhaL - 1][2] = ' ';
                matriz[linhaL][2] = ' ';
                L--;
                linhaL = L + 4;
                if (matriz[linhaL - 1][2] == '-')
                {
                    printf("**morreu**\n");
                    return 0;
                }
                matriz[linhaL - 1][2] = 'L';
                matriz[linhaL][2] = 'L';
                printf("~~~~~~~~~~~\n");
                for (int i = L; i < (L + 5); i++)
                {
                    for (int j = 0; j < 11; j++)
                        printf("%c", matriz[i][j]);
                    printf("\n");
                }
                printf("~~~~~~~~~~~\n");
            }
        }

        if (C[i] == 'B' && posL == 'D')
        {
            if (matriz[linhaL][6] == '|')
            {
                matriz[linhaL][6] = '<';
                printf("~~~~~~~~~~~\n");
                for (int i = L; i < (L + 5); i++)
                {
                    for (int j = 0; j < 11; j++)
                        printf("%c", matriz[i][j]);

                    printf("\n");
                }
                printf("~~~~~~~~~~~\n");
                continue;
            }
            else
            {
                matriz[linhaL - 1][8] = ' ';
                matriz[linhaL][8] = ' ';
                L--;
                linhaL = L + 4;
                if (matriz[linhaL - 1][8] == '-')
                {
                    printf("**morreu**\n");
                    return 0;
                }
                matriz[linhaL - 1][8] = 'L';
                matriz[linhaL][8] = 'L';
                printf("~~~~~~~~~~~\n");
                for (int i = L; i < (L + 5); i++)
                {
                    for (int j = 0; j < 11; j++)
                        printf("%c", matriz[i][j]);
                    printf("\n");
                }
                printf("~~~~~~~~~~~\n");
            }
        }
    }
    return 0;
}
