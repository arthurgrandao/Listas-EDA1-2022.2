#include <stdio.h>
#include <string.h>
int main() {
    int marciano = 0;
    char x[31];
    while (scanf("%30s", x) != EOF)
    {
        fflush(stdin);
        if (strcmp(x, "marte") == 0)
            marciano = 1;
        else if (strcmp(x, "marte") == 0 && marciano != 1)
            marciano = 0;
    }
    if (marciano == 1)
        printf("Leonardo Cicero Marciano");
    else
        printf("none");
}