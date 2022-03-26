#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int num[100];
	int maxn = INT32_MIN;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
		maxn = max(maxn, num[i]);
	}
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (num[i] != maxn)
			cnt += num[i];
	}
	cout << cnt;
	return 0;
}