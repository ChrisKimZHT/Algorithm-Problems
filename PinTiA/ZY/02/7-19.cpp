#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N, ans1, ans2;
	cin >> N;
	bool prime[1000010];
	memset(prime, 1, sizeof prime);
	prime[1] = false;
	for (int i = 2; i < 1000010; i++)
	{
		if (prime[i] == false)
			continue;
		for (int j = 2; j < 1000010 / i; j++)
		{
			prime[i * j] = false;
		}
	}
	for (int i = 2; i < N; i++)
	{
		if (!prime[i])
		{
			continue;
		}
		int temp = N - i;
		int j;
		bool is_prime = true;
		for (j = 2; j < sqrt(temp + 1); j++)
		{
			if (temp % j == 0)
			{
				is_prime = false;
			}
		}
		if (is_prime)
		{
			ans1 = i;
			ans2 = temp;
			break;
		}
	}
	cout << N << " = " << ans1 << " + " << ans2 << endl;
	return 0;
}