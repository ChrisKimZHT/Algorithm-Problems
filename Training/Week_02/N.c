#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count, num;
    double result = 0;
    double a;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &num);
        a = 1;
        result = 0;
        for (int j = 0; j < num; j++)
        {
            if (j % 2 == 0)
            {
                result += a;
            }
            else
            {
                result -= a;
            }
            a = 1.0 / (j + 2);
        }
        printf("%.2lf\n", result);
    }
    system("pause");
    return 0;
}