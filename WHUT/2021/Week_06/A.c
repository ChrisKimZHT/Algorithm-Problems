#include <stdio.h>
#include <stdlib.h>

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
			int l1 = 0, r1 = n - 1;
			int l2 = 0, r2 = n - 1;
			int A, B;
			scanf("%d%d", &A, &B);
			while (l1 < r1)
			{
				int mid = (l1 + r1) >> 1;
				if (point[mid] >= A)
					r1 = mid;
				else
					l1 = mid + 1;
			}
			while (l2 < r2)
			{
				int mid = (l2 + r2 + 1) >> 1;
				if (point[mid] <= B)
					l2 = mid;
				else
					r2 = mid - 1;
			}
			if (B < point[0] || A > point[n - 1])
				printf("0\n");
			else
				printf("%d\n", l2 - l1 + 1);
		}
	}
	system("pause");
	return 0;
}