#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>

using namespace std;

int _k(int _p);

long m, k, sum_p, max_p;
long p[500];
long sep[500];

int main(void)
{
	int N;
	scanf("%d", &N);
	while (N--)
	{
		sum_p = max_p = 0;
		scanf("%ld%ld", &m, &k);
		for (int i = 0; i < m; i++)
		{
			scanf("%ld", &p[i]);
			sum_p += p[i];
			if (p[i] > max_p)
			{
				max_p = p[i];
			}
		}
		long l = max_p, r = sum_p;
		while (l < r)
		{
			int mid = l + (r - l) / 2;
			if (_k(mid) <= k)
				r = mid;
			else
				l = mid + 1;
		}
		long sum = 0, count = 0, remain = k;
		memset(sep, 0, sizeof(sep));
		for (int i = m - 1; i >= 0; i--)
		{
			if (sum + p[i] > r || i + 1 < remain)
			{
				sum = p[i];
				sep[i] = 1;
				remain--;
			}
			else
			{
				sum += p[i];
			}
		}
		for (int i = 0; i < m - 1; i++)
		{
			printf("%d ", p[i]);
			if (sep[i])
				printf("/ ");
		}
		printf("%d\n", p[m - 1]);
		/*int last[510];
		long long done = 0;
		memset(last, 0, sizeof(last));
		int remain = k;
		for (int i = m - 1; i >= 0; i--)
		{
			if (done + p[i] > l || i + 1 < remain)
			{
				last[i] = 1;
				remain--;
				done = p[i];
			}
			else
			{
				done += p[i];
			}
		}
		for (int i = 0; i < m - 1; i++)
		{
			printf("%d ", p[i]);
			if (last[i])
				printf("/ ");
		}
		printf("%d\n", p[m - 1]);*/
	}
	system("pause");
	return 0;
}

int _k(int _p)
{
	long sum = 0;
	int ans = 1;
	for (int i = 0; i < m; i++)
	{
		if (sum + p[i] <= _p)
		{
			sum += p[i];
		}
		else
		{
			sum = p[i];
			ans++;
		}
	}
	return ans;
}