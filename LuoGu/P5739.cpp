#include <bits/stdc++.h>

using namespace std;

unsigned long long factorial(int x)
{
	if (x == 1)
		return 1;
	else
		return x * factorial(x - 1);
}

int main(void)
{
	int n;
	cin >> n;
	cout << factorial(n);
	return 0;
}