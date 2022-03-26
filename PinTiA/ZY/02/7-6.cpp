#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int M, N;
	cin >> M >> N;
	bool prime[1100];
	memset(prime, 1, sizeof prime);
	prime[1] = false;
	for (int i = 2; i < 1000; i++)
	{
		if (prime[i] == false)
			continue;
		for (int j = 2; j < 1000 / i; j++)
		{
			prime[i * j] = false;
		}
	}
	int count = 0, sum = 0;
	for (int i = M; i <= N; i++)
	{
		if (prime[i] == true)
		{
			count++;
			sum += i;
		}
	}
	cout << count << ' ' << sum << endl;
	return 0;
}