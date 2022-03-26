#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	int power[10];
	cin >> N;
	int start = pow(10, N - 1), end = pow(10, N) - 1;
	for (int i = 0; i <= 9; i++)
	{
		power[i] = pow(i, N);
	}
	for (int i = start; i <= end; i++)
	{
		int temp = i, sum = 0;
		while (temp)
		{
			int digit = temp % 10;
			sum += power[digit];
			temp /= 10;
		}
		if (sum == i)
		{
			cout << i << endl;
		}
	}
	return 0;
}