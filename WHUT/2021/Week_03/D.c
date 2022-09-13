#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int count, chartmp;
	scanf("%d", &count);
	struct s
	{
		char name[21];
		int point;
	};
	struct s a[count], temp;

	for (int i = 0; i < count; i++)
	{
		int j = 0;
		scanf("%s%d", &a[i].name, &a[i].point);
	}

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			if (a[j].point < a[j + 1].point)
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
			else if (a[j].point == a[j + 1].point)
			{
				if (strcmp(a[j].name, a[j + 1].name) > 0)
				{
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
	}

	for (int i = 0; i < count; i++)
	{
		printf("%s %d\n", a[i].name, a[i].point);
	}

	system("pause");
	return 0;
}