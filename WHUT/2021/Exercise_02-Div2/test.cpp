#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <math.h>
const int INF = 0x3f3f3f3f;
typedef long long LL;
const int mod = 1e9 + 7;
const int maxn = 1e7 + 10;
using namespace std;

struct node
{
	int f;
	int id;
	bool friend operator<(node a, node b)
	{
		if (a.id == b.id)
			return a.f < b.f;
		return a.id < b.id;
	}
} pos[2010];

int main()
{
	int T;
	scanf("%d", &T);
	for (int k = 1; k <= T; k++)
	{
		int n, m;
		int l, r;
		int cnt = 0;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d", &l, &r);
			pos[++cnt].id = l;
			pos[cnt].f = 0;
			pos[++cnt].id = r + 1;
			pos[cnt].f = 1;
		}
		int cot = 0;
		int ans = 0;
		sort(pos + 1, pos + 1 + cnt);
		for (int i = 1; i <= cnt - 1; i++)
		{
			if (pos[i].f)
				cot--;
			else
				cot++;
			if (cot % 2)
				ans += pos[i + 1].id - pos[i].id;
		}
		printf("Case #%d: %d\n", k, ans);
	}
	return 0;
}