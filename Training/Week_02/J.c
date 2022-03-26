#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int x, y, a, b, i;
    while (scanf("%d%d", &x, &y) != EOF)
    {
        if (x > y)
        {
            i = x;
            x = y;
            y = i;
        }
        a = b = 0;
        if (x % 2 != 0)
        {
            for (i = x + 1; i <= y; i += 2)
            {
                a += pow(i, 2);
            }
            for (i = x; i <= y; i += 2)
            {
                b += pow(i, 3);
            }
        }
        else
        {
            for (i = x; i <= y; i += 2)
            {
                a += pow(i, 2);
            }
            for (i = x + 1; i <= y; i += 2)
            {
                b += pow(i, 3);
            }
        }
        printf("%d %d\n", a, b);
    }
    system("pause");
    return 0;
}