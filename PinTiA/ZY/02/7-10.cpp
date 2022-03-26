#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int h, n;
	cin >> h >> n;
	double dist = 0, bounce = 1.0 * h / 2;
	dist += h;
	for (int i = 0; i < n - 1; i++)
	{
		dist += bounce * 2;
		bounce /= 2;
	}
	if (n == 0)
		printf("0.0 0.0\n");
	else
		printf("%.1lf %.1lf\n", dist, bounce);
	return 0;
}