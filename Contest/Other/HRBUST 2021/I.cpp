#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, x = 0, y = 0;
	cin >> n;
	int cnt = 1;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		while (x != a || y != b)
		{
			if (x < a && y < b)
			{
				if (x < y)
				{
					if (y <= a)
					{
						cnt++;
						x = y;
					}
					else
					{
						x = a;
					}
				}
				else if (x > y)
				{
					if (x <= b)
					{
						cnt++;
						y = x;
					}
					else
					{
						y = b;
					}
				}
				else if (x == y)
				{
					int t = min(a, b);
					cnt += t - x;
					x = y = t;
				}
			}
			else if (x < a || y == b)
			{
				if (x < y)
					cnt++;
				x = a;
			}
			else if (y < b || x == a)
			{
				if (y < x)
					cnt++;
				y = b;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}