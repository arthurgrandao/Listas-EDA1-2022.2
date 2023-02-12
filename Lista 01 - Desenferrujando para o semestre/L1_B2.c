#include <stdio.h>
int main() {
    int soma = 0;
    int vezes = 0;
    int a = 0;
    scanf("%d", &vezes);
    for (size_t i = 0; i < vezes; i++)
    {
        scanf("%d", &a);
        soma += a;
    }
    printf("%d\n", soma);
}
