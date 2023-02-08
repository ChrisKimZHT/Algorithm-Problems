#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	if (n % 2 == 0)
	{
		while (n)
		{
			int t = 1;
			while (2 * t <= n)
			{
				t *= 2;
			}
			cout << t << ' ';
			n -= t;
		}
	}
	else
	{
		cout << "-1";
	}
	return 0;
}