#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	// freopen("P1102_3.in", "r", stdin);
	int N, C;
	int num[200020];
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}
	sort(num, num + N);
	long long count = 0;
	for (int i = 0; i < N; i++)
	{
		int r1 = lower_bound(num, num + N, num[i] - C) - num;
		int r2 = upper_bound(num, num + N, num[i] - C) - num;
		count += (r2 - r1);
	}
	cout << count << endl;
	return 0;
}