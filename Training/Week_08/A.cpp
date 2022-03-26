#include <iostream>

using namespace std;

int main(void)
{
	int n, ans;
	cin >> n;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			ans = n / i;
			break;
		}
	}
	cout << ans;
	return 0;
}