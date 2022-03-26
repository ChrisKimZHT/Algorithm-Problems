#include <iostream>
#include <climits>

using namespace std;

int n;
int a[200000], b[200000];
long long lcount[200000], rcount[200000];

int main(void)
{
	long long ans = LONG_MAX;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 2; i <= n; i++)
		b[i] = a[i] - a[i - 1];

	for (int i = 2; i <= n; i++)
		lcount[i] = b[i] <= 0 ? lcount[i - 1] - b[i] + 1 : lcount[i - 1];
	for (int i = n; i >= 2; i--)
		rcount[i] = b[i] >= 0 ? rcount[i + 1] + b[i] + 1 : rcount[i + 1];
	for (int i = 1; i <= n; i++)
	{
		ans = min(ans, (long long)max(lcount[i], rcount[i + 1]));
	}
	printf("%lld\n", ans);
	system("pause");
	return 0;
}