#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int line, i, x, y;
    scanf("%d", &line);
    for (i = 0; i < line; i++)
    {
        scanf("%d%d", &x, &y);
        int j;
        int a = 0;
        int b = 0;
        for (j = 1; j < x; j++)
        {
            if (x % j == 0)
            {
                a += j;
            }
        }
        for (j = 1; j < y; j++)
        {
            if (y % j == 0)
            {
                b += j;
            }
        }
        if (x == b && y == a)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    //system("pause");
    return 0;
}