#include <stdio.h>

int soma_digitos_int(int num)
{
    if (num/10 == 0) 
        return num;
    return ((num%10) + soma_digitos_int(num/10));
}

int soma_digitos_str(char *num_str)
{
    if (num_str[0] == '\0')
        return 0;
    return ((int)(num_str[0]) - 48) + soma_digitos_str(num_str+1);
}

int grau9(int x)
{
    if (x == 9)
        return 1;
    else if (x % 9 == 0)
        return 1 + grau9(soma_digitos_int(x));
    else
        return -1000;
}


int main(void)
{
    char num[1001];
    int g9;

    while (scanf("%s", num) == 1 && num[0] != '0')
    {
        g9 = grau9(soma_digitos_str(num));

        if (g9 <= 0) 
            printf("%s is not a multiple of 9.\n", num);
        else
            printf("%s is a multiple of 9 and has 9-degree %d.\n", num, g9);
    }

    return 0;
}