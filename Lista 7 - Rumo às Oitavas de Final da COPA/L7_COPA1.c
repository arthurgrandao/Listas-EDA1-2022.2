#include <stdio.h>

int main()
{
    int e,j1,j2;

    char jog1 = 'A'-2, jog2 = 'B'-2;
    char q[8], s[4], f[2];

    for (size_t i = 0; i < 8; i++)
    {
        jog1+=2, jog2+=2;

        scanf("%d %d", &j1, &j2);

        if (j1 > j2)
            q[i] = jog1;
        else
            q[i] = jog2;
    }

    size_t count = 0;
    for (size_t i = 0; i < 8; i+=2)
    {
        jog1 = q[i], jog2 = q[i+1];

        scanf("%d %d", &j1, &j2);

        if (j1 > j2)
            s[count] = jog1;
        else
            s[count] = jog2;
        count++;
    }

    count = 0;
    for (size_t i = 0; i < 4; i+=2)
    {
        jog1 = s[i], jog2 = s[i+1];

        scanf("%d %d", &j1, &j2);

        if (j1 > j2)
            f[count] = jog1;
        else
            f[count] = jog2;
        count++;
    }

    jog1 = f[0], jog2 = f[1];
    scanf("%d %d", &j1, &j2);
    
    if (j1 > j2)
            printf("%c\n", f[0]);
        else
            printf("%c\n", f[1]);

    return 0;
}
