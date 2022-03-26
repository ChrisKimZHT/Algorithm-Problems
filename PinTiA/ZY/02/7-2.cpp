#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	double eps, a = INT32_MAX, ans = 0;
	cin >> eps;
	int x = 1;
	for (int i = 0; a > eps; i++)
	{
		a = 1.0 / x;
		x += 3;
		ans += pow(-1, i) * a;
	}
	printf("sum = %.6lf", ans);
	return 0;
}