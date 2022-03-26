#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input, output;
    while (scanf("%d", &input) != EOF)
    {
        output = 1;
        for (int i = 1; i < input; i++)
        {
            output = (output + 1) * 2;
        }
        printf("%d\n", output);
    }
    system("pause");
    return 0;
}