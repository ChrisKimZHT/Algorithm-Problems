#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, i, sum;
    sum = 0;
    scanf("%d%d", &a, &b);
    if (a % 2 == 0)
    {
        a++;
    }
    for (i = a; i <= b; i = i + 2)
    {
        sum += i;
    }
    printf("%d", sum);
    //system("pause");
    return 0;
}