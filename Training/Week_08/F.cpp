#include <iostream>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		long long n, B, _B = 1;
		cin >> n >> B;
		int a = 9971;
		while (a != 0)
		{
			if (a % 2 == 1)
			{
				_B = _B * B % 9973;
			}
			B = B * B % 9973;
			a >>= 1;
		}
		cout << (n * (_B + 9973 * 2)) % 9973 << endl;
	}
	return 0;
}