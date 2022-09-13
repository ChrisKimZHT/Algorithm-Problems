#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int input, sumall = 0, sumleft = 0, sum = 0;
	scanf("%d", &input);
	int left = 0, right = 0;
	while (right < input)
	{
		sum = sumall - sumleft;
		if (sum < input)
		{
			right++;
			sumall += right;
		}
		else if (sum > input)
		{
			left++;
			sumleft += left;
		}
		else if (sum == input)
		{
			printf("%d %d\n", left + 1, right);
			right++;
			sumall += right;
		}
	}
	system("pause");
	return 0;
}