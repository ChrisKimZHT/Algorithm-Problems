#include <stdio.h>
#include <stdlib.h>

int main()
{
	int count;
	scanf("%d", &count);
	struct st
	{
		int one;
		char str[201];
	} a[count], temp;
	for (int i = 0; i < count; i++)
	{
		scanf("%s", &a[i].str);
		int onecount = 0;
		for (int j = 0; a[i].str[j] != '\0'; j++)
		{
			if (a[i].str[j] == '1')
				onecount++;
			a[i].one = onecount;
		}
	}
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			if (a[j].one > a[j + 1].one)
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < count; i++)
	{
		printf("%s\n", a[i].str);
	}

	system("pause");
	return 0;
}