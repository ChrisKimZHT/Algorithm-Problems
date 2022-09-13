#include <bits/stdc++.h>
#define SIZE 1000010
using namespace std;

int a[SIZE];
int dist[4][SIZE];
stack<int> st1, st2, st3, st4;

int main(void)
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	// 找i左边第一个比i小的数
	for (int i = 0; i < n; i++)
	{
		while (!st1.empty() && a[st1.top()] > a[i])
		{
			st1.pop();
		}
		dist[0][i] = st1.empty() ? i + 1 : (i - st1.top());
		st1.push(i);
	}
	// 找i右边第一个比i小的数
	for (int i = n - 1; i >= 0; i--)
	{
		while (!st2.empty() && a[st2.top()] >= a[i])
		{
			st2.pop();
		}
		dist[1][i] = st2.empty() ? n - i : (st2.top() - i);
		st2.push(i);
	}
	// 找i左边第一个比i大的数
	for (int i = 0; i < n; i++)
	{
		while (!st3.empty() && a[st3.top()] < a[i])
		{
			st3.pop();
		}
		dist[2][i] = st3.empty() ? i + 1 : (i - st3.top());
		st3.push(i);
	}
	// 找i右边第一个比i大的数
	for (int i = n - 1; i >= 0; i--)
	{
		while (!st4.empty() && a[st4.top()] <= a[i])
		{
			st4.pop();
		}
		dist[3][i] = st4.empty() ? n - i : (st4.top() - i);
		st4.push(i);
	}
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += (long long)a[i] * ((long long)dist[2][i] * dist[3][i] - (long long)dist[0][i] * dist[1][i]);
	}
	cout << ans << endl;
	return 0;
}