#include <stdio.h>

int soma_digitos(unsigned long long int num)
{
    if (num == 0)
        return 0;
    return ((num%10) + soma_digitos(num/10));
}

int main(void) 
{
    unsigned long long int num = 0;
    scanf("%llu", &num);
    printf("%d\n", soma_digitos(num));
}

/* 
---------Método usando string---------

#include <stdio.h>

int soma_digitos(char *num_str)
{
    if (num_str[0] == '\0')
        return 0;
    return ((int)(num_str[0]) - 48) + soma_digitos(num_str+sizeof(char));
}

int main(void) 
{
    char num[14];
    scanf("%s", num);
    printf("%d\n", soma_digitos(num));
}
*/