#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	double ans = 1;
	for (int i = 1; i <= n; i++)
	{
		double temp = 1;
		for (int j = 1; j <= i; j++)
		{
			temp /= j;
		}
		ans += temp;
	}
	printf("%.8lf", ans);
	return 0;
}