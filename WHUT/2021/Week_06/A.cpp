#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int point[100000];

int main(void)
{
	int T;
	int x = 1;
	scanf("%d", &T);
	while (T--)
	{
		printf("Case %d:\n", x++);
		int n, q;
		scanf("%d%d", &n, &q);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &point[i]);
		}
		while (q--)
		{
			int A, B;
			scanf("%d%d", &A, &B);
			int a = int(upper_bound(point, point + n, B) - point);
			int b = int(lower_bound(point, point + n, A) - point);
			printf("%d\n", a - b);
		}
	}
	system("pause");
	return 0;
}