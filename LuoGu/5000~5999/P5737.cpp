#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int x, y, cnt = 0;
	cin >> x >> y;
	stringstream ans;
	for (int i = x; i <= y; i++)
	{
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
		{
			ans << i << ' ';
			cnt++;
		}
	}
	cout << cnt << '\n'
		 << ans.str() << endl;
	return 0;
}