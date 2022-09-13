#include <stdio.h>
#include <stdlib.h>

int main()
{
	int count, old;
	double c1 = 0, c2 = 0, c3 = 0, c4 = 0;
	scanf("%d", &count);
	for (int i = 0; i < count; i++)
	{
		scanf("%d", &old);
		if (old >= 0 && old <= 18)
			c1++;
		else if (old >= 19 && old <= 35)
			c2++;
		else if (old >= 36 && old <= 60)
			c3++;
		else
			c4++;
	}
	printf("%.2lf%%\n", c1 / count * 100);
	printf("%.2lf%%\n", c2 / count * 100);
	printf("%.2lf%%\n", c3 / count * 100);
	printf("%.2lf%%", c4 / count * 100);
	system("pause");
	return 0;
}