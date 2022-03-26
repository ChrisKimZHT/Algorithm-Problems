#include <bits/stdc++.h>
#define SIZE 200010

using namespace std;

struct INT_WITH_ID
{
	long long value;
	int id;
} a[SIZE];

bool cmp(INT_WITH_ID a, INT_WITH_ID b)
{
	return a.value < b.value;
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &a[i].value);
		a[i].id = i;
	}
	sort(a, a + N, cmp);
	set<int> range;
	range.insert(-1);
	range.insert(N);
	long long ans = 0;
	for (int i = 0; i < N; i++)
	{
		auto begin = range.upper_bound(a[i].id);
		auto end = begin;
		begin--;
		ans += a[i].value * (a[i].id - *begin) * (*end - a[i].id);
		range.insert(a[i].id);
	}
	cout << ans << endl;
	return 0;
}