#include <bits/stdc++.h>

using namespace std;

void init(int);
int find(int);
void merge(int, int);

int fa[1010];

int main(void)
{
	while (1)
	{
		int n, m;
		cin >> n;
		if (!n)
			break;
		init(n);
		cin >> m;
		while (m--)
		{
			int x, y;
			cin >> x >> y;
			merge(x, y);
		}
		bool flag[1010]{};
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			flag[find(i)] = true;
		}
		for (int i = 1; i <= n; i++)
		{
			if (flag[i])
				count++;
		}
		cout << count - 1 << endl;
	}
	return 0;
}

void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
}

int find(int x)
{
	return (fa[x] == x) ? x : (fa[x] = find(fa[x]));
}

void merge(int x, int y)
{
	fa[find(y)] = find(x);
}