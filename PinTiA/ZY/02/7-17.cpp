#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int m, n;
	bool x = false;
	cin >> m >> n;
	for (int i = m; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j < i; j++)
		{
			if (i % j == 0)
			{
				sum += j;
			}
		}
		if (sum == i)
		{
			x = true;
			cout << i << " = ";
			for (int j = 1; j < i; j++)
			{
				if (i % j == 0)
				{
					if (j != 1)
					{
						cout << " + ";
					}
					cout << j;
				}
			}
			cout << endl;
		}
	}
	if (!x)
	{
		cout << "None" << endl;
	}
	return 0;
}