#include <iostream>
#include <cstring>

using namespace std;

int n, k;
bool map[10][10];
int ans;
bool flag[10];

void dfs(int col, int cnt)
{
	if (cnt == k)
	{
		ans++;
		return;
	}
	for (int _col = col; _col < n; _col++)
	{
		for (int row = 0; row < n; row++)
		{
			if (!flag[row] && map[row][_col])
			{
				flag[row] = true;
				dfs(_col + 1, cnt + 1);
				flag[row] = false;
			}
		}
	}
}

int main(void)
{
	while (cin >> n >> k && n != -1 && k != -1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				char t;
				cin >> t;
				if (t == '#')
				{
					map[i][j] = true;
				}
				else
				{
					map[i][j] = false;
				}
			}
		}
		memset(flag, 0, sizeof(flag));
		ans = 0;
		dfs(0, 0);
		cout << ans << endl;
	}
	return 0;
}