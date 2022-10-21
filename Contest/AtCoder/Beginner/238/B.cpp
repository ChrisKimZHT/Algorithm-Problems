#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	set<int> cut;
	int N;
	cin >> N;
	int D = 0;
	cut.insert(D);
	for (int i = 0; i < N; i++)
	{
		int A;
		cin >> A;
		D += A;
		D %= 360;
		cut.insert(D);
	}
	int ans = 0;
	for (auto it = cut.begin(); next(it) != cut.end(); ++it)
	{
		ans = max(ans, *next(it) - *it);
	}
	ans = max(ans, 360 - *prev(cut.end()));
	cout << ans << endl;
	return 0;
}