#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, L, R;
	cin >> n >> L >> R;
	int max = 2 * n - 1;
	if (max >= L && max <= R)
	{
		cout << n - 1 << endl;
	}
	else if (max > R)
	{
		cout << R - n << endl;
	}
	else if (max < L)
	{
		while (max < L)
		{
			max += n;
			if (max >= L && max <= R)
			{
				cout << n - 1 << endl;
				break;
			}
			else if (max > R)
			{
				cout << R % n << endl;
				break;
			}
		}
	}
	return 0;
}