#include <bits/stdc++.h>
using namespace std;
#define ll long long
int p[100005] = {0, 1}, vis[100005];
ll vex[100005];
vector<ll> ans[100005];
vector<int> link[100005], son[100005];
void buildtree(int x)
{
	if (vis[x])
		return; // 不加不会死循环，但会重复运行两次
	vis[x] = 1;
	for (auto i : link[x])
	{
		if (!p[i])
		{
			p[i] = x;
			son[x].push_back(i);
			buildtree(i);
		}
	}
}
void dfs(int x)
{
	for (auto i : son[x])
	{
		dfs(i); // i 结点还没有处理过
		for (auto j : ans[i])
			ans[x].push_back(j);
	}
	sort(ans[x].begin(), ans[x].end());
	while (ans[x].size() > 20)
		ans[x].erase(ans[x].begin());
}
int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &vex[i]), ans[i].push_back(vex[i]);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		link[a].push_back(b);
		link[b].push_back(a);
	}
	buildtree(1);
	dfs(1);
	for (int i = 0; i < q; i++)
	{
		int v, k;
		scanf("%d %d", &v, &k);
		printf("%lld\n", ans[v][ans[v].size() - k]);
	}
	return 0;
}