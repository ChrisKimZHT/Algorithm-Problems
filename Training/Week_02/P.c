#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count;
    double a, b, c, buffer;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        scanf("%lf%lf%lf", &a, &b, &c);
        if (a > b)
        {
            buffer = a;
            a = b;
            b = buffer;
        }
        if (b > c)
        {
            buffer = b;
            b = c;
            c = buffer;
        }
        if (a > b)
        {
            buffer = a;
            a = b;
            b = buffer;
        }
        if (a + b > c)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    system("pause");
    return 0;
}