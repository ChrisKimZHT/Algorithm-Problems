#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b;
    double c, d;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        d = 0;
        c = (double)a;
        for (int i = 0; i < b; i++)
        {
            d += c;
            c = sqrt(c);
        }
        printf("%.2lf\n", d);
    }
    system("pause");
    return 0;
}