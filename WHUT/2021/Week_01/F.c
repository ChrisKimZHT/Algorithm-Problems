#include <stdio.h>

int main()
{
	int count, input, sum, i;
	while(scanf("%d", &count) != EOF)
	{
		sum = 0;
		for(i=0; i<count; i++)
		{
			scanf("%d", &input);
			sum += input;
		}
		printf("%d\n", sum);
	}
	return 0;
}