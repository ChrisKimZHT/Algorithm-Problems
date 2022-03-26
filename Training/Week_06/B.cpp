#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(void)
{
	int T, N, a[2000];
	int ans;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		ans = 0;
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &a[j]);
		}
		sort(a, a + N);
		for (int p = 0; p < N - 1; p++)
		{
			for (int q = p + 1; q < N; q++)
			{
				int sum = a[p] + a[q];
				int temp = lower_bound(a + q, a + N, sum) - a;
				ans += temp - 1 - q;
			}
		}
		printf("Case %d: ", i + 1);
		printf("%d\n", ans);
	}
	system("pause");
	return 0;
}