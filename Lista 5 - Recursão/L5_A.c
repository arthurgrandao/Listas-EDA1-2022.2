#include <stdio.h>

int pares(char *ch)
{
    if (ch[1] == '\0')
        return 0;
 
    if (ch[0] == ch[2])
        return 1 + pares(ch + 1);
    else
        return pares(ch + 1);
}

int main(void)
{
    char palavra[201];

    scanf("%s", palavra);

    printf("%d\n", pares(palavra));

    return 0;
}