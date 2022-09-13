#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	else
	{
		return a.first < b.first;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int cse = 1; cse <= T; cse++)
	{
		int n;
		cin >> n;
		vector<pair<int, int>> point(n);
		for (int i = 0; i < n; i++)
		{
			cin >> point[i].first >> point[i].second;
		}
		/*
		map<pair<int, int>, int> mid;
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				mid[make_pair(point[i].first + point[j].first, point[i].second + point[j].second)]++;
			}
		}
		int ans = 0;
		for (auto it = mid.begin(); it != mid.end(); ++it)
		{
			if (it->second > 1)
			{
				ans += it->second * (it->second - 1) / 2;
			}
		}
		*/
		vector<pair<int, int>> mid;
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				mid.push_back(make_pair(point[i].first + point[j].first, point[i].second + point[j].second));
			}
		}
		sort(mid.begin(), mid.end(), cmp);
		int ans = 0;
		for (int i = 0; i < mid.size() - 1; i++)
		{
			for (int j = i + 1; j < mid.size(); j++)
			{
				if (mid[i] == mid[j])
					ans++;
				else
					break;
			}
		}
		cout << "Case " << cse << ": " << ans << endl;
	}
	return 0;
}