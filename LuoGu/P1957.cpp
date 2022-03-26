#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int i;
	char a;
	cin >> i;
	while (i--)
	{
		getchar();
		int x, y;
		if (!(cin >> x))
		{
			cin.clear();
			cin >> a >> x;
		}
		cin >> y;
		stringstream out;
		if (a == 'a')
		{
			out << x << '+' << y << '=' << x + y;
		}
		else if (a == 'b')
		{
			out << x << '-' << y << '=' << x - y;
		}
		else if (a == 'c')
		{
			out << x << '*' << y << '=' << x * y;
		}
		string strout;
		out >> strout;
		cout << strout << '\n'
			 << strout.length() << endl;
	}
	return 0;
}