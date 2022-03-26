#include <bits/stdc++.h>
#define SIZE 200010

using namespace std;

long long a[SIZE];

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &a[i]);
	}
	long long ans = 0;
	for (int l = 0; l < N; l++)
	{
		long long minn = INT64_MAX;
		for (int r = l; r < N; r++)
		{
			minn = min(minn, a[r]);
			ans += minn;
		}
	}
	cout << ans << endl;
	return 0;
}