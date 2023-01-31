#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    int res, not;
    int contador = 1;
    
    while (scanf("%d %d %d", &num, &res, &not) != EOF)
    {    
        printf("Dia %d\n", contador);
        
        int resposta[num];
        int nota[num];

        resposta[0] = res;
        nota[0] = not;

        if (num > 1) {
            int *res_p = resposta+1;
            int *nota_p = nota+1;

            int i;
            for (i = 1; i < num; i++)
            {
                scanf("%d", res_p);
                scanf("%d", nota_p);
                res_p++;
                nota_p++;
            }

            int comparadorn = 0,
                comparadorr = 10000000,
                contador2 = 0;

            for (size_t i = 0; i < num; i++)
            {
                if (nota[i] > comparadorn)
                {
                    comparadorn = nota[i];
                    comparadorr = resposta[i];
                }
                
                if (nota[i] == comparadorn && resposta[i] < comparadorr) {
                    comparadorn = nota[i];
                    comparadorr = resposta[i];
                }
            }        

            printf("%d\n\n", comparadorr);
        } 
        else
            printf("%d\n\n", resposta[0]);

        contador++;
    } 
    return 0;
}