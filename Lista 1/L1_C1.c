#include <stdio.h>
int main()
{
    int contador = 0, contador2 = 0;
    int depositos;
    int dif = 0;
    int j = 0, z = 0;

    do
    {
        depositos = 0, dif = 0;
        scanf("%d", &depositos);
        if (depositos > 0)
        {
            printf("Teste %d\n", (contador+1));
            for (size_t i = 0; i < depositos; i++)
            {
                scanf("%d %d", &j, &z);
                dif += (j - z);
                printf("%d\n", dif);
                contador2++;
            }
            printf("\n");
            contador++;
        }
    } while (depositos > 0);
}
