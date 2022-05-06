#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int w, x, h, q;
	bool block[20][20][20];
	memset(block, 1, sizeof block);
	cin >> w >> x >> h;
	cin >> q;
	while (q--)
	{
		int x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		for (int i = x1 - 1; i <= x2 - 1; i++)
		{
			for (int j = y1 - 1; j <= y2 - 1; j++)
			{
				for (int k = z1 - 1; k <= z2 - 1; k++)
				{
					block[i][j][k] = false;
				}
			}
		}
	}
	int count = 0;
	for (int i = 0; i <= w - 1; i++)
	{
		for (int j = 0; j <= x - 1; j++)
		{
			for (int k = 0; k <= h - 1; k++)
			{
				if (block[i][j][k])
				{
					count++;
				}
			}
		}
	}
	cout << count << endl;
	return 0;
}