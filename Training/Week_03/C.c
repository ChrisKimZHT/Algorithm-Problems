#include <stdio.h>
#include <stdlib.h>

int main()
{
	int count;
	scanf("%d", &count);
	struct point
	{
		int num;
		int sum;
		int chin;
		int math;
		int eng;
	};
	struct point a[count], temp;
	for (int i = 0; i < count; i++)
	{
		a[i].num = i + 1;
		scanf("%d%d%d", &a[i].chin, &a[i].math, &a[i].eng);
		a[i].sum = a[i].chin + a[i].math + a[i].eng;
	}

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			if (a[j].sum < a[j + 1].sum)
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
			else if (a[j].sum == a[j + 1].sum)
			{
				if (a[j].chin < a[j + 1].chin)
				{
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
				else if (a[j].chin == a[j + 1].chin)
				{
					if (a[j].num > a[j + 1].num)
					{
						temp = a[j];
						a[j] = a[j + 1];
						a[j + 1] = temp;
					}
				}
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d %d\n", a[i].num, a[i].sum);
	}
	system("pause");
	return 0;
}