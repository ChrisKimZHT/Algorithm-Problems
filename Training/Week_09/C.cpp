#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, ans;
	while (cin >> n)
	{
		ans = 1;
		for (int i = 1; i < n; i++)
		{
			ans = (ans + 1) * 2;
		}
		cout << ans << endl;
	}
	return 0;
}