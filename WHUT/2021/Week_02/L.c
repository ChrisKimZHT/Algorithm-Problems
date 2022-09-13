#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x, y, z;
    while (scanf("%c%c%c", &x, &y, &z) != EOF)
    {
        char a;
        if (x > y)
        {
            a = x;
            x = y;
            y = a;
        }
        if (y > z)
        {
            a = y;
            y = z;
            z = a;
        }
        if (x > y)
        {
            a = x;
            x = y;
            y = a;
        }
        printf("%c %c %c\n", x, y, z);
        getchar();
    }
    system("pause");
    return 0;
}