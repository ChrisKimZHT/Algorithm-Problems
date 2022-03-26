#include <bits/stdc++.h>

using namespace std;

int a[1000010];
int _a[1000010];

int main(void)
{
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
		_a[i] = a[i];
	}
	sort(a, a + m);
	sort(_a, _a + m, greater<int>());
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		int b;
		cin >> b;
		// cout << endl;
		// cout << a[lower_bound(a, a + m, b) - a] - b << endl;
		// cout << _a[lower_bound(_a, _a + m, b, greater<int>()) - _a] - b << endl;
		int *lb = lower_bound(a, a + m, b), *_lb = lower_bound(_a, _a + m, b, greater<int>());
		if (lb >= a + m)
			result += (b - _a[_lb - _a]);
		else if (_lb >= _a + m)
			result += (a[lb - a] - b);
		else
			result += min(b - _a[_lb - _a], a[lb - a] - b);
	}
	cout << result;
	return 0;
}