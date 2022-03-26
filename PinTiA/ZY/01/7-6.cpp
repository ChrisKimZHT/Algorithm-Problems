#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(void)
{
	double a, b, c, s, perimeter;
	double area;
	cin >> a >> b >> c;
	perimeter = a + b + c;
	s = perimeter / 2;
	double x = s * (s - a) * (s - b) * (s - c);
	if (x <= 0)
	{
		cout << "These sides do not correspond to a valid triangle";
	}
	else
	{
		area = sqrt(x);
		printf("area = %.2lf; perimeter = %.2lf", area, (double)perimeter);
	}
	return 0;
}