#include <bits/stdc++.h>

using namespace std;

int seq[10];

void qs(int start, int end)
{
	int l = start, r = end;
	int mid = seq[(l + r) / 2];
	do
	{
		while (seq[l] < mid)
		{
			l++;
		}
		while (seq[r] > mid)
		{
			r--;
		}
		if (l <= r)
		{
			swap(seq[l], seq[r]);
			l++;
			r--;
		}
	} while (l <= r);
	if (start < r)
	{
		qs(start, r);
	}
	if (l < end)
	{
		qs(l, end);
	}
}

int main(void)
{
	int n, i = 0;
	cin >> n;
	while (n--)
	{
		cin >> seq[i++];
	}
	// sort(seq, seq + i);
	qs(0, i - 1);
	while (i)
	{
		cout << seq[--i];
		if (i > 0)
		{
			cout << ' ';
		}
	}
	return 0;
}