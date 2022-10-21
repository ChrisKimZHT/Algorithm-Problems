#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		long long a, s;
		cin >> a >> s;
		long long x = s - 2 * a;
		if (x >= 0 && !(x & a))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}