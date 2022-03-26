#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	map<int, int> cnt;
	int num, N;
	cin >> N;
	while (N--)
	{
		cin >> num;
		cnt[num]++;
	}
	int maxc = 0, maxn;
	for (map<int, int>::iterator iter = cnt.begin(); iter != cnt.end(); ++iter)
	{
		if (iter->second > maxc)
		{
			maxc = iter->second;
			maxn = iter->first;
		}
	}
	cout << maxn << ' ' << maxc;
	return 0;
}