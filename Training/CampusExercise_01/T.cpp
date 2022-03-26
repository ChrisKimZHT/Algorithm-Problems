#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	double cnt = 0;
	while (n--)
	{
		int t;
		cin >> t;
		cnt += ceil(1.0 * t / 70);
	}
	printf("%.1lf\n", cnt * 0.1);
	return 0;
}