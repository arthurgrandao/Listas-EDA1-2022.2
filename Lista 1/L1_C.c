#include <stdio.h>
int main() {
    int vezes = 0;
    int a = 0;
    int alice;
    int beto;
    do
    {
        scanf("%d", &vezes);
        if (vezes > 0)
        {
            alice = 0;
            beto = 0;
            for (size_t i = 0; i < vezes; i++)
            {
                scanf("%d", &a);
                if (a == 0)
                    alice += 1;
                else if (a == 1)
                    beto += 1;
            }
            printf("Alice ganhou %d e Beto ganhou %d\n", alice, vezes-alice);
        }
    } while (vezes > 0);
}