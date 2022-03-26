#include <bits/stdc++.h>

using namespace std;

int cnt(int day)
{
	if (day == 1)
		return 1;
	else
		return (cnt(day - 1) + 1) * 2;
}

int main(void)
{
	int n;
	cin >> n;
	cout << cnt(n) << endl;
	return 0;
}