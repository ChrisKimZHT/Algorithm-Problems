#include <stdio.h>
#include <stdlib.h>

int main()
{
	int count;
	scanf("%d", &count);
	int str[count];
	for (int i = 0; i < count; i++)
	{
		scanf("%d", &str[i]);
	}
	for (int i = 0; i < count; i++)
	{
		printf("%d", str[count - i - 1]);
		if (i != count - 1)
		{
			printf(" ");
		}
	}
	system("pause");
	return 0;
}