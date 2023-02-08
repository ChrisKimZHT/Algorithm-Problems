#include <bits/stdc++.h>

using namespace std;

int x[1000010];

int main(void)
{
	int L, n;
	cin >> L >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	// min
	int mint = 0;
	for (int i = 0; i < n; i++)
	{
		mint = max(mint, min(x[i], L - x[i]));
	}
	cout << mint << ' ';
	//max
	int maxt = 0;
	return 0;
}