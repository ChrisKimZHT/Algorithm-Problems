#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int M, N, X, m = 0;
	cin >> M >> N >> X;
	while (1)
	{
		if (X >= ceil(1.0 * M / N))
		{
			X -= ceil(1.0 * M / N);
			m = M;
		}
		else
		{
			break;
		}
		int cnt = 0;
		while (1)
		{
			m -= N;
			if (m >= 0)
			{
				cnt++;
			}
			else
			{
				break;
			}
		}
		N += cnt;
	}
	cout << N << endl;
	return 0;
}