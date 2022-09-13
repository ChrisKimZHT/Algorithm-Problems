#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int fa[50010];

int find(int x)
{
	return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	int caseid = 1;
	while (n || m)
	{
		for (int i = 1; i <= n; i++)
		{
			fa[i] = i;
		}
		int a, b, cnt = n;
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &a, &b);
			if (find(a) != find(b))
			{
				fa[find(b)] = find(a);
				cnt--;
			}
		}
		printf("Case %d: %d\n", caseid++, cnt);
		scanf("%d%d", &n, &m);
	}
	return 0;
}