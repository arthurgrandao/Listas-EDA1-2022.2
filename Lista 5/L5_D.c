#include <stdio.h>
#include <stdlib.h>

int comparador(char *str, char *sub, char *limite_str, char *limite_sub, int op)
{
    if (str == limite_str && sub != limite_sub)
        return 0;

    if (sub == limite_sub)
        return 1;

    if (*str == *sub)
        return comparador(str + op, sub + op, limite_str, limite_sub, op);
    else
        return 0;
}

int indice_sub(char *str, char *sub, int indice, char *limite_str, char *limite_sub, int op)
{
    if (str == limite_str)
        return -1;

    if (*str == *sub)
        if (comparador(str, sub, limite_str, limite_sub, op))
            return indice;
        else
            return indice_sub(str + op, sub, indice + op, limite_str, limite_sub, op);
    else
        return indice_sub(str + op, sub, indice + op, limite_str, limite_sub, op);
}

int main(void)
{

    size_t size = 100,
           str_sz,
           sub_sz;

    char *str = malloc(size),
         *sub = malloc(size);

    str_sz = getline(&str, &size, stdin);
    sub_sz = getline(&sub, &size, stdin);

    str[str_sz - 1] = '\0';
    sub[sub_sz - 1] = '\0';

    if (str_sz > 2)
    {
        // indice_sub(String, Substring, Índice inicial, Fim da String, Fim da Substring, Ler do inicio(1) ou do fim(-1));
        int inicio = indice_sub(str, sub, 0, &str[str_sz - 1], &sub[sub_sz - 1], 1);

        if (inicio == -1)
        {
            printf("0\n");
            return 0;
        }

        int fim = indice_sub(&str[str_sz - 2], &sub[sub_sz - 2], str_sz - 2, &str[-1], &sub[-1], -1);

        if (fim != -1)
            printf("%d\n", (fim + 1) - inicio);
        else
            printf("%d\n", inicio);
    }
    else if (str_sz <= 1 || sub_sz <= 1)
        printf("0\n");
    else //(str_sz = 2) ['x', '\0']
        if (sub_sz > 2)
            printf("0\n");
        else if (*str == *sub)
            printf("1\n");
        else
            printf("0\n");

    return 0;
}