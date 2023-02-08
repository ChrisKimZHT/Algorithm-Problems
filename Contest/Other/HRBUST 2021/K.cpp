#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int j, a, y, m, n, ans;
	string x;
	j = a = y = m = n = ans = 0;
	cin >> x;
	int pos = 0;
	while (pos < x.length())
	{
		if (pos + 2 < x.length() &&
			(x[pos] == 'J' && x[pos + 1] == 'a' && x[pos + 2] == 'y' ||
			 x[pos] == 'y' && x[pos + 1] == 'a' && x[pos + 2] == 'J'))
		{
			m++;
			pos += 3;
		}
		else
		{
			if (x[pos] == 'J')
				j++;
			else if (x[pos] == 'a')
				a++;
			else
				y++;
			pos++;
		}
	}
	n += min(j, min(a, y));
	if (!n)
	{
		if (m > 0)
		{
			ans = 1;
			m--;
		}
		else
			ans = 0;
	}
	else
	{
		ans = n;
	}
	for (int i = 0; i < m; i++)
	{
		ans = ans * 2 % 1000000007;
	}
	cout << ans;
	return 0;
}