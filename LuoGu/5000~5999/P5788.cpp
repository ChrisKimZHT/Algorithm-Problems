#include <bits/stdc++.h>
#define SIZE 3000010

using namespace std;

int num[SIZE];
long long ans[SIZE];

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	stack<int> st;
	for (int i = n - 1; i >= 0; i--)
	{
		while (!st.empty() && num[st.top()] <= num[i])
		{
			st.pop();
		}
		ans[i] = st.empty() ? 0 : (st.top() + 1);
		st.push(i);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%lld ", ans[i]);
	}
	return 0;
}