#include <bits/stdc++.h>

using namespace std;

map<int, int> diff[100010];
map<int, int> goods;

int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int l, r, d;
		cin >> l >> r >> d;
		diff[l][d]++;
		diff[r + 1][d]--;
	}
	int maxc = 0, warehouse;
	for (int i = 1; i <= n; i++)
	{
		for (auto it = diff[i].begin(); it != diff[i].end(); ++it)
		{
			goods[it->first] += it->second;
			if (goods[it->first] <= 0)
				goods.erase(goods.find(it->first));
		}
		if (goods.size() > maxc)
		{
			maxc = goods.size();
			warehouse = i;
		}
	}
	cout << warehouse << endl;
	return 0;
}