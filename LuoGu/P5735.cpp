#include <bits/stdc++.h>

using namespace std;

double length(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main(void)
{
	double x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	double a, b, c, p;
	a = length(x1, y1, x2, y2);
	b = length(x1, y1, x3, y3);
	c = length(x2, y2, x3, y3);
	// p = (a + b + c) / 2;
	// double ans = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("%.2lf", a + b + c);
	return 0;
}