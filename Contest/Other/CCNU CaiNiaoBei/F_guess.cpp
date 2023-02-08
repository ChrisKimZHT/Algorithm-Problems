#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	int t;
	while (a)
	{
		t = b % a;
		b = a;
		a = t;
	}
	return b;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main(void)
{
	// 猜测用
	// freopen("C:\\Users\\ChrisKim\\Desktop\\out.txt", "w", stdout);
	int X, Y, Z;
	cin >> X >> Y >> Z;
	int cnt = 0;
	for (int i = 1; i <= X; i++)
	{
		for (int j = 1; j <= Y; j++)
		{
			for (int k = 1; k <= Z; k++)
			{
				if (i + j + k == lcm(lcm(i, j), k))
					cnt++;
				// cout << i << ' ' << j << ' ' << k << endl;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}