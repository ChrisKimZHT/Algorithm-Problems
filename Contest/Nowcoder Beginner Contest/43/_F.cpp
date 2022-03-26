#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<int> connect[200010];
vector<int> people;
bool dis[200010][2];
queue<int> que;

void bfs(void)
{
	queue<pair<int, bool>> que;
	que.push({people[0], 0});
	while (!que.empty())
	{
		pair<int, bool> now = que.front();
		que.pop();
		for (int i = 0; i < connect[now.first].size(); i++)
		{
			pair<int, bool> next = {connect[now.first][i], now.second ? 0 : 1};
			if (!dis[next.first][next.second])
			{
				dis[next.first][next.second] = 1;
				que.push({next.first, next.second});
			}
		}
	}
}

int main(void)
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		connect[u].push_back(v);
		connect[v].push_back(u);
	}
	for (int i = 0; i < k; i++)
	{
		int t;
		scanf("%d", &t);
		people.push_back(t);
	}
	bfs();
	bool flag = true;
	for (int i = 0; i < people.size(); i++)
	{
		if (!dis[people[i]][0])
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}