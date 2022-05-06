#include <bits/stdc++.h>

using namespace std;

int n, k;
int length[100010];

int amount(int l)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += length[i] / l;
	}
	return ans;
}

int main(void)
{
	cin >> n >> k;
	int l = 1, r = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> length[i];
		r = max(r, length[i]);
	}
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (amount(mid) >= k)
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