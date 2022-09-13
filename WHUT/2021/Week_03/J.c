#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	bool a[N];
	for (int i = 0; i < N; i++)
		a[i] = 1;
	for (int i = 0; i < M; i++)
	{
		for (int j = i + 1; j < N + 1; j += i + 1)
		{
			if (a[j - 1])
				a[j - 1] = false;
			else
				a[j - 1] = true;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (!a[i])
		{
			if (i != 0)
				printf(",");
			printf("%d", i + 1);
		}
	}
	system("pause");
	return 0;
}