#include <stdio.h>

int main(void)
{
	int bucket[128] = {0};
	char c;
	while ((c = getchar()) != '\n')
	{
		bucket[c]++;
	}
	for (int ASCII = 0; ASCII < 128; ASCII++)
	{
		if (bucket[ASCII])
		{
			printf("%c", ASCII);
		}
	}
	return 0;
}