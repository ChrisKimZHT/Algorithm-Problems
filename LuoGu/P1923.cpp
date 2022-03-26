#include <bits/stdc++.h>

using namespace std;

int num[5000010];

void srt(int, int, int);

int main(void)
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	srt(0, n - 1, k);
	cout << num[k];
	return 0;
}

void srt(int start, int end, int k)
{
	int mid = num[(start + end) / 2];
	int l = start, r = end;
	do
	{
		while (num[l] < mid)
		{
			l++;
		}
		while (num[r] > mid)
		{
			r--;
		}
		if (l <= r)
		{
			swap(num[r], num[l]);
			l++;
			r--;
		}
	} while (l <= r);
	if (k <= r)
	{
		srt(start, r, k);
	}
	else if (k >= l)
	{
		srt(l, end, k);
	}
}