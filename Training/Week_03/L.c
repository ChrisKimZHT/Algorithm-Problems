#include <stdio.h>
#include <stdlib.h>

int main()
{
	int dim, result = 0, temp;
	scanf("%d", &dim);
	int value1[dim], value2[dim];
	for (int i = 0; i < dim; i++)
	{
		scanf("%d", &value1[i]);
	}
	for (int i = 0; i < dim; i++)
	{
		scanf("%d", &value2[i]);
	}
	for (int i = 0; i < dim; i++)
	{
		temp = value1[i] * value2[i];
		result += temp;
	}
	printf("%d", result);
	system("pause");
	return 0;
}