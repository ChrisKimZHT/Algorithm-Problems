#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, a[110], b[110];
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		int win = 0;
		bool defeated[110]{};
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!defeated[j])
				{
					if (a[i] > b[j])
					{
						win++;
						defeated[j] = true;
						break;
					}
				}
			}
		}
		cout << win << endl;
	}
	return 0;
}