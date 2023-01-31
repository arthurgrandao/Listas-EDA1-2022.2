#include <stdio.h>

int f91(int num) 
{
    if (num <= 100)
        return f91(f91(num+11));
    else
        return num-10;
}

int main(void) {
    int num = -1;
    while (scanf("%d", &num) == 1 && num != 0)
        printf("f91(%d) = %d\n", num, f91(num));
    return 0;
}