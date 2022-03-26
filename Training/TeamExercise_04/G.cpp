#include <bits/stdc++.h>
#define SIZE 1000000

using namespace std;

bool is_prime[SIZE];
int prime[SIZE], primesize = 0;
void init_prime()
{
	memset(is_prime, 1, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i < SIZE; i++)
	{
		if (is_prime[i])
			prime[primesize++] = i;
		for (int j = 0; j < primesize && prime[j] * i < SIZE; j++)
		{
			is_prime[prime[j] * i] = false;
			if (i % prime[j] == 0)
				break;
		}
	}
}

long long fact_cnt(long long n)
{
	long long now = n, ans = 1;
	for (int i = 0; i < primesize && prime[i] <= sqrt(now); i++)
	{
		int cnt = 0;
		while (now % prime[i] == 0)
		{
			cnt++;
			now /= prime[i];
		}
		ans *= (cnt + 1);
	}
	if (now != 1)
		ans *= 1 + 1;
	return ans;
}

int main(void)
{
	init_prime();
	int T;
	cin >> T;
	for (int cse = 1; cse <= T; cse++)
	{
		long long a, b;
		cin >> a >> b;
		long long ans = 0;
		if (a >= b * b)
		{
			ans = fact_cnt(a) / 2;
			for (int i = 1; i < b; i++)
			{
				if (a % i == 0)
					ans--;
			}
		}
		cout << "Case " << cse << ": " << ans << endl;
	}
	return 0;
}
