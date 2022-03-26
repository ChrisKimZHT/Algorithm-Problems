#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	if (n > 0)
	{
		cout << "sign(" << n << ") = " << 1;
	}
	else if (n == 0)
	{
		cout << "sign(" << n << ") = " << 0;
	}
	else if (n < 0)
	{
		cout << "sign(" << n << ") = " << -1;
	}
	return 0;
}