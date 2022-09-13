#include <cstdio>

using namespace std;

int fa[4020], rnk[4020];

void init(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		fa[i] = i;
		rnk[i] = 1;
	}
}

int find(int x)
{
	return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

void merge(int i, int j)
{
	int x = find(i), y = find(j);
	if (rnk[x] <= rnk[y])
		fa[x] = y;
	else
		fa[y] = x;
	if (rnk[x] == rnk[y] && x != y)
		rnk[y]++;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	int id = 1;
	while (T--)
	{
		int bug, inter;
		scanf("%d%d", &bug, &inter);
		init(bug * 2);
		bool flag = true;
		for (int i = 0; i < inter; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			if (find(a) == find(b))
			{
				flag = false;
			}
			merge(a, b + bug);
			merge(b, a + bug);
		}
		printf("Scenario #%d:\n", id++);
		if (flag)
		{
			printf("No suspicious bugs found!\n\n");
		}
		else
		{
			printf("Suspicious bugs found!\n\n");
		}
	}
	return 0;
}