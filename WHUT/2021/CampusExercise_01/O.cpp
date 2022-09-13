#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	bool prime[20000];
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i < 20000; i++)
	{
		if (prime[i])
		{
			for (int j = 2; j * i < 20000; j++)
			{
				prime[j * i] = false;
			}
		}
	}
	int _prime[10000];
	int pos = 0;
	for (int i = 0; i < 20000; i++)
	{
		if (prime[i])
		{
			_prime[pos++] = i;
		}
	}
	bool flag = false;
	for (int i = 1; i < pos; i++)
	{
		if (_prime[i] > n)
			break;
		if (_prime[i] - _prime[i - 1] == 2)
		{
			cout << _prime[i - 1] << " " << _prime[i] << endl;
			flag = true;
		}
	}
	if (!flag)
		cout << "empty" << endl;
	return 0;
}