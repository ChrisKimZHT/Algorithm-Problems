#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
	int length, temp;
	bool jolly = true;
	scanf("%d", &length);
	int num[length], num2[length - 1];
	for (int i = 0; i < length; i++)
	{
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < length - 1; i++)
	{
		num2[i] = abs(num[i + 1] - num[i]);
	}

	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 2; j++)
		{
			if (num2[j] > num2[j + 1])
			{
				temp = num2[j];
				num2[j] = num2[j + 1];
				num2[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < length - 1; i++)
	{
		if (num2[i] != i + 1)
		{
			jolly = false;
		}
	}

	if (jolly)
	{
		printf("Jolly");
	}
	else
	{
		printf("Not jolly");
	}
	system("pause");
	return 0;
}