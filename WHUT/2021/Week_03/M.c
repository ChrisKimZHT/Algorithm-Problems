#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m, n, matrix[5][5], temp;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	scanf("%d%d", &m, &n);
	m--;
	n--;
	for (int i = 0; i < 5; i++)
	{
		temp = matrix[m][i];
		matrix[m][i] = matrix[n][i];
		matrix[n][i] = temp;
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}