#include <iostream>

using namespace std;

int gcd(int, int);
int lcm(int, int);

int main(void)
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << gcd(a, b) << " " << lcm(a, b) << endl;
	}
	return 0;
}

int gcd(int a, int b)
{
	if (b != 0)
	{
		return gcd(b, a % b);
	}
	else
	{
		return a;
	}
}

int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}