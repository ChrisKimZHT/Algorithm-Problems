#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	bool prime[1000100];
	memset(prime, 1, sizeof prime);
	prime[1] = false;
	for (int i = 2; i < 1000000; i++)
	{
		if (prime[i] == false)
			continue;
		for (int j = 2; j < 1000000 / i; j++)
		{
			prime[i * j] = false;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		int x = (pow(2, i) - 1);
		if (prime[x] == true)
		{
			cout << x << endl;
		}
	}
	if (n == 1)
	{
		cout << "None" << endl;
	}
	return 0;
}