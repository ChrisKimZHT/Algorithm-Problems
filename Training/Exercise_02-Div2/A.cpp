#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	long long sum[50010];
	cin >> sum[1];
	for (int i = 2; i <= N; i++)
	{
		int tmp;
		cin >> tmp;
		sum[i] = sum[i - 1] + tmp;
	}
	int Q;
	cin >> Q;
	for (int t = 1; t <= Q; t++)
	{
		int i, l;
		cin >> i >> l;
		cout << sum[i + l - 1] - sum[i - 1] << endl;
	}
	return 0;
}