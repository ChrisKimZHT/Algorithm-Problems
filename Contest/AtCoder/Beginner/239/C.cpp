#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	pair<int, int> dot1, dot2;
	cin >> dot1.first >> dot1.second >> dot2.first >> dot2.second;
	map<pair<int, int>, int> cnt;
	pair<int, int> t[8] = {{1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}, {-1, 2}, {-2, 1}};
	for (int i = 0; i < 8; i++)
	{
		cnt[{dot1.first + t[i].first, dot1.second + t[i].second}]++;
		cnt[{dot2.first + t[i].first, dot2.second + t[i].second}]++;
	}
	bool flag = false;
	for (auto it = cnt.begin(); it != cnt.end(); ++it)
	{
		if (it->second > 1)
			flag = true;
	}
	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}