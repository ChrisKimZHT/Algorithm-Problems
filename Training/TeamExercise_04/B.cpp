#include <bits/stdc++.h>
#define eps 1e-4

using namespace std;

long long profit(long long T, long long N, long long C)
{
	return T * (C - T * N);
}

int main(void)
{
	int num_case;
	cin >> num_case;
	for (int i = 1; i <= num_case; i++)
	{
		long long N, C;
		cin >> N >> C;
		if (!N)
		{
			cout << "Case " << i << ": 0" << endl;
			continue;
		}
		long long l = 0, r = 60000000;
		while (r - l > eps)
		{
			long long m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
			if (profit(m1, N, C) < profit(m2, N, C))
				l = m1 + 1;
			else
				r = m2 - 1;
		}
		cout << "Case " << i << ": " << l << endl;
	}
	return 0;
}