#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dr(long input);

int main()
{
	char input[10000];
	int input2, length;
	while (scanf("%s", &input) != EOF)
	{
		if (input[0] == '0')
			break;
		length = strlen(input);
		input2 = 0;
		for (int i = 0; i < length; i++)
			input2 += input[i] - '0';
		printf("%d\n", dr(input2));
	}
	system("pause");
	return 0;
}

int dr(long input)
{
	int ans = 0;
	while (input > 0)
	{
		ans += input % 10;
		input /= 10;
	}
	return ans < 10 ? ans : dr(ans);
}