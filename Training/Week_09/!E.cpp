#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N, K, D, X, Y, count = 0;
	cin >> N >> K;
	while (K--)
	{
		cin >> D >> X >> Y;
		if (X > N || Y > N)
		{
			count++;
			continue;
		}
		if (D == 2 && X == Y)
		{
			count++;
			continue;
		}
		}

	return 0;
}