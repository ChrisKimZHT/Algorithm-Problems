#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> bit(30);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		int t = A[i];
		for (int i = 0; t; i++, t >>= 1)
		{
			bit[i] += t & 1;
		}
	}
	long long sum = accumulate(A.begin(), A.end(), 0LL);
	for (int i = 0; i < N; i++)
	{
		long long cur_sum = 0, d = 1;
		int t = A[i], bit_sum;
		for (int j = 0; j < 30; j++)
		{
			if (t & 1)
			{
				bit_sum = N - bit[j];
			}
			else
			{
				bit_sum = bit[j];
			}
			t >>= 1;
			cur_sum += d * bit_sum;
			d <<= 1;
		}
		sum = max(sum, cur_sum);
	}
	cout << sum << endl;
	return 0;
}