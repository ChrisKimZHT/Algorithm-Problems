#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	int m, n, same = 0;
	scanf("%d%d", &m, &n);
	bool pixel1[m][n], pixel2[m][n];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &pixel1[i][j]);
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &pixel2[i][j]);
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (pixel1[i][j] == pixel2[i][j])
				same++;
		}
	}
	printf("%.2lf", (double)same / (m * n) * 100);
	system("pause");
	return 0;
}