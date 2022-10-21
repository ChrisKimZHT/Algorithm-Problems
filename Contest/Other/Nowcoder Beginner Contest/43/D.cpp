#include <bits/stdc++.h>
#define SIZE 500100

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int odd = 0;
	int pos[SIZE];
	int p = 0;
	for (int i = 1; i <= n; i++)
	{
		int t;
		scanf("%d", &t);
		if (t % 2)
		{
			odd++;
			pos[p++] = i;
		}
	}
	long long ans = 0;
	int l = 1;
	for (int i = 0; i < p; i++)
	{
		ans += (pos[i] - l + 1) * (n - pos[i] + 1);
		l = pos[i] + 1;
	}
	cout << ans << endl;
	return 0;
}