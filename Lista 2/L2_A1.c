#include <stdio.h>

int main() {
    int vezes, num, soma, soma1;
    
    scanf("%d", &vezes);
    scanf("%d", &num);
    soma1 += num;
    
    for (size_t i = 1; i < vezes; i++)
    {
        scanf("%d", &num);
        soma1 += num;
    }
    
    scanf("%d", &soma);

    if (soma1 == soma)
        printf("Acertou\n");
    else 
        printf("Errou\n");
}