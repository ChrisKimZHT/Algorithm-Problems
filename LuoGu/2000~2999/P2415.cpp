#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int s[30];
	int cnt = -1;
	while (scanf("%d", &s[++cnt]) != EOF)
		;
	long long ans = 0;
	for (int i = 0; i < cnt; i++)
	{
		ans += s[i] * pow(2, cnt - 1);
	}
	cout << ans << endl;
	return 0;
}