#include <bits/stdc++.h>

using namespace std;

void hanoi(int, string, string, string);

int main(void)
{
	int n;
	string a, b, c;
	cin >> n >> a >> b >> c;
	hanoi(n, a, b, c);
	return 0;
}

void hanoi(int n, string a, string b, string c)
{
	if (n == 1)
	{
		cout << n << ':' << a << "->" << c << endl;
	}
	else
	{
		hanoi(n - 1, a, c, b);
		cout << n << ':' << a << "->" << c << endl;
		hanoi(n - 1, b, a, c);
	}
}