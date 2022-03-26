#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	if (T == 1)
	{
		printf("I love Luogu!\n");
	}
	else if (T == 2)
	{
		printf("%d %d\n", 2 + 4, 10 - 2 - 4);
	}
	else if (T == 3)
	{
		printf("%d\n%d\n%d\n", 14 / 4, 14 / 4 * 4, 14 - 14 / 4 * 4);
	}
	else if (T == 4)
	{
		printf("%.3lf\n", (double)500 / 3);
	}
	else if (T == 5)
	{
		printf("%d\n", (260 + 220) / (12 + 20));
	}
	else if (T == 6)
	{
		cout << sqrt(6 * 6 + 9 * 9);
	}
	else if (T == 7)
	{
		printf("%d\n%d\n%d\n", 100 + 10, 100 + 10 - 20, 0);
	}
	else if (T == 8)
	{
		double const pi = 3.141593;
		double const r = 5;
		cout << pi * r * 2 << endl
			 << pi * r * r << endl
			 << 4.0 / 3 * pi * r * r * r << endl;
	}
	else if (T == 9)
	{
		printf("%d\n", (((1 + 1) * 2 + 1) * 2 + 1) * 2);
	}
	else if (T == 10)
	{
		printf("%d\n", 9);
	}
	else if (T == 11)
	{
		cout << 1.0 * 100 / 3;
	}
	else if (T == 12)
	{
		printf("%d\n%c\n", 'M' - 'A' + 1, 'A' + 18 - 1);
	}
	else if (T == 13)
	{
		printf("%d\n", (int)pow((double)4 / 3 * 3.141593 * (4 * 4 * 4 + 10 * 10 * 10), (double)1 / 3));
	}
	else if (T == 14)
	{
		printf("%d\n", 50);
	}
	return 0;
}