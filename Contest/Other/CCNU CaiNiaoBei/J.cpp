#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int X, Y, Z;
		cin >> X >> Y >> Z;
		double ha, he;
		ha = 1.0 * min(X, Y) / 2;
		he = 1.0 * Z / 2;
		if (ha > he)
			cout << "xiaoha" << endl;
		else if (ha < he)
			cout << "xiaohe" << endl;
		else
			cout << "ping" << endl;
	}
	return 0;
}