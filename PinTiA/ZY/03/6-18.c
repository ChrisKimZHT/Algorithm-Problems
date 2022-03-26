#include <stdio.h>
#include <math.h>

unsigned int reverse(unsigned int number);

int main()
{
	unsigned int n;

	scanf("%u", &n);
	printf("%u\n", reverse(n));

	return 0;
}

/* 请在这里填写答案 */
unsigned int reverse(unsigned int number)
{
	unsigned int digit[100], length = 0;
	while (number)
	{
		digit[length] = number % 10;
		number /= 10;
		length++;
	}
	unsigned int ans = 0;
	for (int i = 0; i < length; i++)
	{
		ans += pow(10, length - i - 1) * digit[i];
	}
	return ans;
}