#include <stdio.h>

int main(void) {
    int linhas;

    scanf("%d", &linhas);
    getchar();

    int size[linhas];
    int m1[linhas][1000];
    char line[1000];

    for (size_t i = 0; i < linhas; i++)
    {
        scanf("%[^\n]", line);
        getchar();

        int count = 0,
            tamanho = 0;
        
        while ((int) line[count] != '\0')
        {
            tamanho++;
            count++;
        }

        size[i] = tamanho;
        
        for (size_t j = 0; j < tamanho; j++)
            m1[i][j] = line[j];
        
    }
    int comp = 0;
    for (size_t k = 0; k < linhas; k++)
    {
        if (size[k] > comp)
            comp = size[k];
    }

    int m2[linhas][comp];

    for (size_t i = 0; i < linhas; i++)
    {
        for (size_t j = 0; j < comp; j++)
            m2[i][j] = m1[i][j];
    }

    int linha, coluna;
    
    scanf("%d %d", &linha, &coluna);
    linha--;
    coluna--;

    char comando;
    while (scanf("%c", &comando) != EOF)
    {
        if (comando == 'j') 
        {
            if (linha < linhas-1) 
                linha++;

            if (coluna >= size[linha]) 
                printf("%d %d %c\n", linha+1, size[linha], m2[linha][size[linha]-1]);
            else 
                printf("%d %d %c\n", linha+1, coluna+1, m2[linha][coluna]);
        }
        else if (comando == 'k')
        {
            if (linha > 0) 
                linha--; 
            if (coluna >= size[linha]) 
                printf("%d %d %c\n", linha+1, size[linha], m2[linha][size[linha]-1]);
            else 
                printf("%d %d %c\n", linha+1, coluna+1, m2[linha][coluna]);
        }
    }
    
    return 0;
}