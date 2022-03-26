#include <stdio.h>

int main()
{
	int count, input, sum, i, row, j;
	scanf("%d", &row);
	for(j=0; j<row ; j++)
	{
		if(j != 0)
		{
			printf("\n");
		}
		sum = 0;
		scanf("%d", &count);
		for(i=0; i < count; i++)
		{
			scanf("%d", &input);
			sum += input;
		}
		printf("%d\n", sum);
	}
	return 0;
}