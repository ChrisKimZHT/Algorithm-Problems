#include <stdio.h>

int main(void)
{
	int scale, num = 1;
	scanf("%d", &scale);
	for (int i = 0; i < scale; i++)
	{
		for (int j = 0; j < scale; j++)
		{
			printf("%02d", num);
			num++;
		}
		printf("\n");
	}
	printf("\n");
	num = 1;
	for (int i = 0; i < scale; i++)
	{
		for (int j = 0; j < scale; j++)
		{
			if (j >= scale - i - 1)
			{
				printf("%02d", num);
				num++;
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	return 0;
}