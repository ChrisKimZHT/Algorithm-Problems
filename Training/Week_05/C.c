#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, q;
	int beat[100], ques[1000], note[10000];
	int time;
	while (scanf("%d%d", &n, &q) != EOF)
	{
		time = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &beat[i]);
		for (int i = 0; i < q; i++)
			scanf("%d", &ques[i]);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < beat[i]; j++)
			{
				note[time + j] = i;
			}
			time += beat[i];
		}
		for (int i = 0; i < q; i++)
		{
			printf("%d\n", note[ques[i]] + 1);
		}
	}
	system("pause");
	return 0;
}