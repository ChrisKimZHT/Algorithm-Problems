#include <bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long n, i;
	cin >> n;
	unsigned long long int sum = 0;
	sum = n * (n + 1) / 2; //等差数列求和
	if (n < 100000000)
	{
		for (i = sum / 2; sum % i != 0 && i >= sqrt(sum); i--)
			; //通过求最小因数计算最大因数 节省时间
		cout << i;
	}
	else
	{ //n超过1亿时从2开始可节约大量时间
		for (i = 2; i < sqrt(n); i++)
		{
			if (sum % i == 0)
			{
				sum /= i;
				break;
			}
		}
		cout << sum;
	}

	return 0;
}