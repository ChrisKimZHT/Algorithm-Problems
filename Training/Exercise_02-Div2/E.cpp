#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1e5 + 10;
long long V[SIZE], T[SIZE], presumT[SIZE];

int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> V[i];
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i];
		presumT[i] = presumT[i - 1] + T[i];
	}
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 1; i <= N; i++)
	{
		pq.push(V[i] + presumT[i - 1]);
		long long ans = pq.size() * T[i];
		while (!pq.empty() && pq.top() <= presumT[i])
		{
			ans -= presumT[i] - pq.top();
			pq.pop();
		}
		cout << ans << ' ';
	}
	cout << endl;
	return 0;
}