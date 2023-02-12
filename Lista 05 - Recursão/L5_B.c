#include <stdio.h>
#include <stdlib.h>

void xpory(char *str)
{
    if (str[0] != '\0')
    {
        if (str[0] == 'x')
        {
            str[0] = 'y';
            xpory(str + 1);
        }
        else
            xpory(str + 1);
    }
    else
        return;
}

int main(void)
{
    size_t tambuff = 81;

    char *str = malloc(tambuff);

    getline(&str, &tambuff, stdin);

    xpory(str);

    printf("%s", str);

    free(str);

    return 0;
}