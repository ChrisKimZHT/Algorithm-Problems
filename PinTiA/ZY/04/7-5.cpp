#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N, num[10];
	cin >> N;
	for (int i = 0; i <= N; i++)
	{
		cin >> num[i];
	}
	sort(num, num + N + 1);
	for (int i = 0; i <= N; i++)
	{
		cout << num[i] << ' ';
	}
	return 0;
}