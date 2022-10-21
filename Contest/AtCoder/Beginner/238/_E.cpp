#include <bits/stdc++.h>
#define MAXN 200010

using namespace std;

int fa[MAXN];
inline void init(int n)
{
	for (int i = 0; i < n; i++)
		fa[i] = i;
}

int find(int x)
{
	return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

inline void merge(int i, int j)
{
	fa[find(i)] = find(j);
}

int main(void)
{
	ios::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	init(N + 1);
	while (Q--)
	{
		int l, r;
		cin >> l >> r;
		merge(l - 1, r);
	}
	if (find(0) == find(N))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}