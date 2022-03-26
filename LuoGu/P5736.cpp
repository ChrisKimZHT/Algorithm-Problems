#include <bits/stdc++.h>

using namespace std;

bool prime[100000];

int main(void)
{
	memset(prime, 1, sizeof prime);
	prime[0] = prime[1] = false;
	for (int i = 2; i < 100000; i++)
	{
		if (prime[i])
		{
			for (int j = 2; j < 100000 / i; j++)
			{
				prime[i * j] = false;
			}
		}
	}
	int n;
	cin >> n;
	while (n--)
	{
		int tmp;
		cin >> tmp;
		if (prime[tmp])
			cout << tmp << ' ';
	}
	return 0;
}