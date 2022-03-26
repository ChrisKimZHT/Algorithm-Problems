#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, arr[10], i = 0;
	cin >> n;
	while (n--)
	{
		cin >> arr[i++];
	}
	while (i)
	{
		cout << arr[--i];
		if (i > 0)
		{
			cout << ' ';
		}
	}
	return 0;
}