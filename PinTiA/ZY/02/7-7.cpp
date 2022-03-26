#include <bits/stdc++.h>

using namespace std;

int generate(int a, int x)
{
	int temp = a, ans = 0;
	for (int i = 0; i < x; i++)
	{
		ans += temp;
		temp *= 10;
	}
	return ans;
}

int main(void)
{
	int a, n, ans = 0;
	cin >> a >> n;
	for (int i = 1; i <= n; i++)
	{
		ans += generate(a, i);
	}
	cout << "s = " << ans << endl;
	return 0;
}