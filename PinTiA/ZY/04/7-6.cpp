#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	map<int, int> cnt;
	cin >> N;
	while (N--)
	{
		int num;
		cin >> num;
		while (num)
		{
			cnt[num % 10]++;
			num /= 10;
		}
	}
	int maxn = 0;
	for (map<int, int>::iterator iter = cnt.begin(); iter != cnt.end(); ++iter)
	{
		maxn = max(maxn, iter->second);
	}
	cout << maxn << ": ";
	bool start = false;
	for (map<int, int>::iterator iter = cnt.begin(); iter != cnt.end(); ++iter)
	{
		if (iter->second == maxn)
		{
			if (start)
			{
				cout << ' ';
			}
			start = true;
			cout << iter->first;
		}
	}
	return 0;
}