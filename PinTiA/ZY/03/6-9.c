#include <stdio.h>

int CountDigit(int number, int digit);

int main()
{
	int number, digit;

	scanf("%d %d", &number, &digit);
	printf("Number of digit %d in %d: %d\n", digit, number, CountDigit(number, digit));

	return 0;
}

/* 你的代码将被嵌在这里 */
int CountDigit(int number, int digit)
{
#include <math.h>
	int count = 0;
	number = abs(number);
	while (1)
	{
		if (number % 10 == digit)
			count++;
		number /= 10;
		if (number == 0)
		{
			break;
		}
	}
	return count;
}