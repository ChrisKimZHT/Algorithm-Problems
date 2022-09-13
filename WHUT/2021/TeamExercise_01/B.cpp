#include <iostream>
#include <stack>
#define SIZE 80010

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int height[SIZE];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &height[i]);
	}
	stack<int> q;
	long long ans = 0;
	for (int i = 0; i < N; i++)
	{
		while (!q.empty() && height[q.top()] <= height[i])
		{
			q.pop();
		}
		ans += q.size();
		q.push(i);
	}
	cout << ans << endl;
	return 0;
}