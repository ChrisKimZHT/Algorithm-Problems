#include <bits/stdc++.h>

using namespace std;

int trans(string);

int main(void)
{
	string a, b;
	cin >> a >> b;
	if (trans(a) == trans(b))
	{
		cout << "GO" << endl;
	}
	else
	{
		cout << "STAY" << endl;
	}
	return 0;
}

int trans(string a)
{
	int ans = 1;
	for (int i = 0; i < a.length(); i++)
	{
		ans *= a[i] - 'A' + 1;
	}
	return ans % 47;
}