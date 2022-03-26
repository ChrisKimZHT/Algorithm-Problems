#include <stdio.h>
#include <stdlib.h>

int main()
{
	double sum = 0;
	int num[10];
	for (int i = 0; i < 10; i++)
		scanf("%d", &num[i]);
	sum = 28.9 * num[0] + 32.7 * num[1] + 45.6 * num[2] + 78 * num[3] + 35 * num[4] + 86.2 * num[5] + 27.8 * num[6] + 43 * num[7] + 56 * num[8] + 65 * num[9];
	printf("%.1lf\n", sum);
	system("pause");
	return 0;
}