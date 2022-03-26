#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int ans = 0;
	while (1)
	{
		int temp;
		cin >> temp;
		if (temp <= 0)
			break;
		if (temp % 2 == 1)
			ans += temp;
	}
	cout << ans;
	return 0;
}