#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int sum = 0, length = 0, N;
	cin >> N;
	while (N)
	{
		sum += N % 10;
		N /= 10;
		length++;
	}
	cout << length << ' ' << sum << endl;
	return 0;
}