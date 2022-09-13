#include <iostream>
#include <stack>
#define SIZE 100010

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	while (n)
	{
		int h[SIZE], length[SIZE];
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &h[i]);
		}
		stack<int> sl;
		for (int i = 0; i < n; i++)
		{
			while (!sl.empty() && h[sl.top()] >= h[i])
			{
				sl.pop();
			}
			length[i] = sl.empty() ? i : (i - sl.top() - 1);
			sl.push(i);
		}
		stack<int> sr;
		for (int i = n - 1; i >= 0; i--)
		{
			while (!sr.empty() && h[sr.top()] >= h[i])
			{
				sr.pop();
			}
			length[i] += sr.empty() ? (n - 1 - i) : (sr.top() - i - 1);
			sr.push(i);
		}
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans = max(ans, (long long)h[i] * (length[i] + 1));
		}
		cout << ans << endl;
		cin >> n;
	}
	return 0;
}