#include <bits/stdc++.h>

using namespace std;

int sche[500010], pos[500010];
stringstream ans;
int num = 0;

void myswap(int a, int b)
{
	swap(sche[a], sche[b]);
	swap(pos[sche[a]], pos[sche[b]]);
	ans << a << ' ' << b << endl;
	num++;
}

int main(void)
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> sche[i];
		pos[sche[i]] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		if (pos[i] == i)
			continue;
		if (abs(pos[i] - i) >= n / 2)
		{
			myswap(i, pos[i]);
		}
		else
		{
			int big = max(i, pos[i]), small = min(i, pos[i]);
			if (big <= n / 2)
			{
				myswap(big, n);
				myswap(small, n);
				myswap(big, n);
			}
			else if (small > n / 2)
			{
				myswap(1, small);
				myswap(1, big);
				myswap(1, small);
			}
			else
			{
				myswap(small, n);
				myswap(1, big);
				myswap(1, n);
				myswap(small, n);
				myswap(1, big);
			}
		}
	}
	cout << "0\n"
		 << num << endl;
	cout << ans.str();
	return 0;
}