#include <bits/stdc++.h>
#define min(a, b) ((a > b) ? b : a)

using namespace std;

int main(void)
{
	int n, num, minn = INT32_MAX;
	cin >> n;
	while (n--)
	{
		cin >> num;
		minn = min(minn, num);
	}
	cout << "min = " << minn;
	return 0;
}