#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	double x1, y1, x2, y2;
	double dist;
	while (scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2) != EOF)
	{
		dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		printf("%.2lf\n", dist);
	}
	//system("pause");
	return 0;
}