#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		long long A, B, target, sum;
		cin >> A >> B >> target;
		sum = A + B;
		if (A == target || B == target)
		{
			cout << "0" << endl;
			continue;
		}
		int ans = 1;
		if (target % 2)
		{
			cout << "-1" << endl;
			continue;
		}
		else
		{
			target /= 2;
			while (target >= sum)
			{
				sum *= 2;
				ans++;
			}
			cout << ans << endl;
		}
	}

	return 0;
}