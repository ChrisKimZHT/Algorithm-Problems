#include <bits/stdc++.h>

using namespace std;

int N;
int A[20][20];
bool vis[20];
int ans = 0;
vector<pair<int, int>> v;
void dfs()
{
	if (v.size() == N)
	{
		int ret = 0;
		for (auto it = v.begin(); it != v.end(); ++it)
		{
			ret ^= A[it->first][it->second];
		}
		ans = max(ret, ans);
		return;
	}
	int a;
	for (int i = 1; i <= 2 * N; i++)
	{
		if (!vis[i])
		{
			a = i;
			vis[a] = true;
			break;
		}
	}
	for (int i = 1; i <= 2 * N; i++)
	{
		if (!vis[i])
		{
			vis[i] = true;
			v.push_back({a, i});
			dfs();
			vis[i] = false;
			v.pop_back();
		}
	}
	vis[a] = false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= 2 * N - 1; i++)
	{
		for (int j = i + 1; j <= 2 * N; j++)
		{
			cin >> A[i][j];
		}
	}
	dfs();
	cout << ans << endl;
	return 0;
}