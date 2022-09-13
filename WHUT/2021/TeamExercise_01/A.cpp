#include <bits/stdc++.h>
#define SIZE 1000010

using namespace std;

int value[SIZE];

int main(void)
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &value[i]);
	}
	deque<int> q;
	for (int i = 0; i < n; i++)
	{
		while (!q.empty() && value[q.back()] > value[i])
		{
			q.pop_back();
		}
		q.push_back(i);
		if (i >= k - 1)
		{
			while (!q.empty() && q.front() < i - k + 1)
			{
				q.pop_front();
			}
			printf("%d ", value[q.front()]);
		}
	}
	cout << endl;
	deque<int> p;
	for (int i = 0; i < n; i++)
	{
		while (!p.empty() && value[p.back()] < value[i])
		{
			p.pop_back();
		}
		p.push_back(i);
		if (i >= k - 1)
		{
			while (!p.empty() && p.front() < i - k + 1)
			{
				p.pop_front();
			}
			printf("%d ", value[p.front()]);
		}
	}
	return 0;
}