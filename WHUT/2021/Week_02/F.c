#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, i, count, num;
    count = 0;
    scanf("%d", &a);
    for (i = 0; i < a; i++)
    {
        scanf("%d", &num);
        if (num % 10 - num / 1000 % 10 - num / 100 % 10 - num / 10 % 10 > 0)
            count++;
    }
    printf("%d", count);
    //system("pause");
    return 0;
}