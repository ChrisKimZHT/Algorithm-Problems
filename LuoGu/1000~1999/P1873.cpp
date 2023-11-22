#include <bits/stdc++.h>

using namespace std;

long long wood(int, int);

int height[1000010];

int main(void)
{
	int N, M;
	int l = 0, r = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &height[i]);
		r = max(r, height[i]);
	}
	sort(height, height + N);
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (wood(mid, N) >= M)
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	cout << r - 1 << endl;
	return 0;
}

long long wood(int H, int N)
{
	long long ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (height[i] > H)
		{
			ans += (height[i] - H);
		}
	}
	return ans;
}