#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<string> str;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		str.push_back(tmp);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int diff = 0;
			for (int pos = 0; pos < m; pos++)
			{
				if (str[i][pos] != str[j][pos])
					diff++;
				if (diff >= 2)
					break;
			}
			if (diff == 0)
				cnt += m;
			else if (diff == 1)
				cnt++;
		}
	}
	cout << cnt * 2 << endl;
	return 0;
}