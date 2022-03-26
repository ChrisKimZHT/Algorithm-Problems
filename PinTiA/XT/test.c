#include <stdio.h>
int main(void)
{
	int N;
	double a = 1, b = 2, temp;
	double sum = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		sum = sum + 1.0 * b / a;
		temp = b;
		b = a + b;
		a = temp;
	}
	printf("%.2lf", sum);
	return 0;
}