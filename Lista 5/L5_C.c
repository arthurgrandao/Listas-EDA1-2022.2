#include <stdio.h>

void str_ao_contrario(char *str)
{
    if (str[0] != '\0')
    {
        str_ao_contrario(str+1);
        printf("%c", str[0]);
    }
    else
        return;
}

int main(void)
{
    char str[501];

    scanf("%s", str);

    str_ao_contrario(str);
    printf("\n");
    
    return 0;
}