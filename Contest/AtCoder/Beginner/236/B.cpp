#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	map<int, int> num;
	for (int i = 0; i < 4 * N - 1; i++)
	{
		int t;
		cin >> t;
		num[t]++;
	}
	for (auto it = num.begin(); it != num.end(); ++it)
	{
		if (it->second != 4)
		{
			cout << it->first << endl;
			break;
		}
	}
	return 0;
}