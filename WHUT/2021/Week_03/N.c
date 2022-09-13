#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, q, temp1, temp2, temp3, temp4;
	scanf("%d%d", &n, &q);
	int score[n];
	for (int i = 0; i < n; i++)
		score[i] = 0;
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d%d%d", &temp1, &temp2, &temp3, &temp4);
		if (temp3 > temp4)
		{
			score[temp1 - 1] += 3;
			score[temp2 - 1] -= 2;
			if (score[temp2 - 1] < 0)
				score[temp2 - 1] = 0;
		}
		if (temp3 < temp4)
		{
			score[temp2 - 1] += 3;
			score[temp1 - 1] -= 2;
			if (score[temp1 - 1] < 0)
				score[temp1 - 1] = 0;
		}
	}
	int max, tmp;
	tmp = score[0];
	max = 0;
	for (int i = 1; i < n; i++)
	{
		if (score[i] > tmp)
		{
			tmp = score[i];
			max = i;
		}
		else if (score[i] == tmp)
		{
			if (i < max)
			{
				tmp = score[i];
				max = i;
			}
		}
	}
	printf("%d", max + 1);
	system("pause");
	return 0;
}