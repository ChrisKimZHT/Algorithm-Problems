#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0;
	cin >> n;
	int result[7];
	for (int i = 0; i < 7; i++)
	{
		cin >> result[i];
	}
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < 7; j++)
		{
			int temp;
			cin >> temp;
			for (int k = 0; k < 7; k++)
			{
				if (temp == result[k])
				{
					count++;
					break;
				}
			}
		}
		if (count == 7)
		{
			a++;
		}
		else if (count == 6)
		{
			b++;
		}
		else if (count == 5)
		{
			c++;
		}
		else if (count == 4)
		{
			d++;
		}
		else if (count == 3)
		{
			e++;
		}
		else if (count == 2)
		{
			f++;
		}
		else if (count == 1)
		{
			g++;
		}
	}
	cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " ";
	return 0;
}