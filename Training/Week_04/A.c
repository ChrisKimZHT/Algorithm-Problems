#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int count, maxcnt, maxi, colcnt[1001];
	char color[1001][16];
	while (scanf("%d", &count) != EOF)
	{
		if (count == 0)
			break;
		for (int i = 0; i < count; i++)
			colcnt[i] = 0;
		maxcnt = 0;
		for (int i = 0; i < count; i++)
			scanf("%s", &color[i]);
		for (int i = 0; i < count - 1; i++)
		{
			for (int j = i + 1; j < count; j++)
			{
				if (strcmp(color[i], color[j]) == 0)
					colcnt[i]++;
			}
		}
		for (int i = 0; i < count; i++)
		{
			if (colcnt[i] > maxcnt)
			{
				maxcnt = colcnt[i];
				maxi = i;
			}
		}
		printf("%s\n", color[maxi]);
	}
	system("pause");
	return 0;
}