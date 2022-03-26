#include <bits/stdc++.h>

using namespace std;

int ticket[20000010];

int main(void)
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> ticket[i];
	}
	sort(ticket, ticket + m);
	for (int i = 0; i < m; i++)
	{
		cout << ticket[i] << ' ';
	}
	return 0;
}