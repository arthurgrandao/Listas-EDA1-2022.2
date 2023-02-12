#include <stdio.h>

void xxxxfuncaoxxxx(char *string)
{
    if (string[0] == '\0')
        return;

    char l = 1;
    if (string[0] == 'x') 
    {
        xxxxfuncaoxxxx(string+l);
        printf("x");
    }
    else 
    {
        printf("%c", string[0]);
        xxxxfuncaoxxxx(string+l);
    }
}

int main(void) {
    char str[101];

    scanf("%s", str);

    xxxxfuncaoxxxx(str);
    printf("\n"); 
}

