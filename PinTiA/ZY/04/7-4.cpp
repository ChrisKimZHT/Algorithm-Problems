#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N, num[10], maxn = 0, minn = INT32_MAX;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
		maxn = max(maxn, num[i]);
		minn = min(minn, num[i]);
	}
	for (int i = 0; i < N; i++)
	{
		if (num[i] == minn)
		{
			swap(num[0], num[i]);
			break;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (num[i] == maxn)
		{
			swap(num[N - 1], num[i]);
			break;
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << num[i] << ' ';
	}
	return 0;
}