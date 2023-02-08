#include <bits/stdc++.h>

using namespace std;

int step(int x)
{
	int res = 0;
	while (1)
	{
		if (x > 3)
		{
			res++;
			x -= 3;
		}
		else
		{
			res++;
			break;
		}
	}
	return res;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int x;
		cin >> x;
		cout << step(abs(x)) << endl;
	}
	return 0;
}