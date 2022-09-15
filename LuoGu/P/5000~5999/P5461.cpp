#include <bits/stdc++.h>

using namespace std;

bool died[1025][1025];

void remit(int x1, int y1, int x2, int y2)
{
	for (int i = x1; i <= (x1 + x2 - 1) / 2; i++)
	{
		for (int j = y1; j <= (y1 + y2 - 1) / 2; j++)
		{
			died[i][j] = false;
		}
	}
	if (x1 != x2 || y1 != y2)
	{
		remit((x1 + x2 - 1) / 2 + 1, y1, x2, (y1 + y2 - 1) / 2);
		remit(x1, (y1 + y2 - 1) / 2 + 1, (x1 + x2 - 1) / 2, y2);
		remit((x1 + x2 - 1) / 2 + 1, (y1 + y2 - 1) / 2 + 1, x2, y2);
	}
}

int main(void)
{
	memset(died, 1, sizeof died);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int size = pow(2, n);
	remit(1, 1, size, size);
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			cout << died[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}