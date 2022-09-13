#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
int a[N];
int ans;
int len;
struct node
{
	int x; //最小初始战斗力
	int y; //怪物数
};
node b[N];
void f(int s)
{
	int n;
	cin >> n;
	int ma = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] - i > ma)
		{
			ma = a[i] - i;
		}
	}
	b[s].x = ma + 1;
	b[s].y = n;
}

int cmp(node a, node b)
{
	return a.x < b.x;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			f(i);
		}
		ans = len = 0;
		sort(b, b + k, cmp);
		for (int i = 0; i < k; i++)
		{
			ans = max(ans, b[i].x - len);
			len += b[i].y;
		}
		cout << ans << endl;
	}
	return 0;
}