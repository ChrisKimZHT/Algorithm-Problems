#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	double x, a, b, c, d;
	cin >> x >> a >> b >> c >> d;
	printf("%.7lf\n", a * x * x * x + b * x * x + c * x + d);
	return 0;
}