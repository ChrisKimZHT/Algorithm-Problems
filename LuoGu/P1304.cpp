#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	int prime[12000], size = 0;
	bool isprime[12000];
	memset(isprime, 1, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	for (int i = 2; i < 12000; i++)
	{
		if (isprime[i])
			prime[size++] = i;
		for (int j = 0; j <= size && i * prime[j] < 12000; j++)
		{
			isprime[i * prime[j]] = false;
			if (i % prime[j] == 0)
				break;
		}
	}
	int N;
	cin >> N;
	for (int i = 4; i <= N; i += 2)
	{
		for (int j = 0; j < size; j++)
		{
			int t = i - prime[j];
			if (isprime[t])
			{
				cout << i << "=" << prime[j] << "+" << t << endl;
				break;
			}
		}
	}
	return 0;
}