#include <stdio.h>
int main() {
    int x = 0;
    int soma = 0;
    while (scanf("%d", &x) == 1)
        soma++;
    printf("%d\n", soma);
}