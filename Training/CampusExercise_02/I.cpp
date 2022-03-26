#include <bits/stdc++.h>

using namespace std;

int abgk[10010][4];

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &abgk[i][0], &abgk[i][1], &abgk[i][2], &abgk[i][3]);
	}
	int x, y;
	cin >> x >> y;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (x >= abgk[i][0] && x <= abgk[i][0] + abgk[i][2] && y >= abgk[i][1] && y <= abgk[i][1] + abgk[i][3])
		{
			ans = i + 1;
		}
	}
	cout << ans << endl;
	return 0;
}