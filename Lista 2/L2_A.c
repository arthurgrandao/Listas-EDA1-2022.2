#include <stdio.h>

int main() {
    int a, b, c, soma;
    
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d", &soma);

    if ((a+b+c) == soma)
        printf("Acertou\n");
    else 
        printf("Errou\n");
}