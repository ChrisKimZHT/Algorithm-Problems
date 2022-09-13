#include <stdio.h>
#include <stdlib.h>

int main()
{
	int length, temp;
	scanf("%d", &length);
	int num[99];
	for (int i = 0; i < 99; i++)
		num[i] = 0;
	for (int i = 0; i < length; i++)
	{
		scanf("%d", &temp);
		num[temp + 49]++;
	}
	int x = 0;
	for (int i = 0; i < 99; i++)
	{
		if (num[i] > length / 2)
		{
			printf("%d", i - 49);
			x = 1;
		}
	}
	if (x == 0)
	{
		printf("no");
	}
	system("pause");
	return 0;
}