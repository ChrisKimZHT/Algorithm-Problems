#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, A;
	cin >> n >> A;
	int cnt5 = A / 5, cnt1;
	if (cnt5 > n)
	{
		cnt5 = n;
		cnt1 = A - 5 * cnt5;
	}
	else
	{
		cnt1 = A - 5 * cnt5;
	}
	cout << cnt5 << ' ' << cnt1 << endl;
	return 0;
}