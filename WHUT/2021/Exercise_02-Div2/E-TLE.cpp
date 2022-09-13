#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int V[100010], T[100010];
	for (int i = 0; i < N; i++)
	{
		cin >> V[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> T[i];
	}
	vector<int> snow;
	for (int i = 0; i < N; i++)
	{
		long long melted = 0;
		snow.push_back(V[i]);
		for (auto it = snow.begin(); it != snow.end(); ++it)
		{
			if (*it - T[i] <= 0)
			{
				melted += *it;
				snow.erase(it--);
			}
			else
			{
				melted += T[i];
				*it -= T[i];
			}
		}
		cout << melted << ' ';
	}
	return 0;
}