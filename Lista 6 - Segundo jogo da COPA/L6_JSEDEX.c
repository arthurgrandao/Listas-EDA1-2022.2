#include <stdio.h>

int main(void)
{
    int bola, a, l, p;

    scanf("%d", &bola);
    scanf("%d %d %d", &a, &l, &p);

    if (bola <= a && bola <= l && bola <= p)
        printf("S\n");
    else
        printf("N\n");

    return 0;
}