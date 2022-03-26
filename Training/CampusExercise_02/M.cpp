#include <bits/stdc++.h>

using namespace std;

pair<int, int> ball[1000010];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main(void)
{
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;

	int k = 0;
	for (int i = 1; i <= K; i++)
	{
		int T;
		cin >> T;
		for (int j = 0; j < T; j++)
		{
			int pos = 0;
			cin >> pos;
			ball[k++] = {pos, i};
		}
	}
	sort(ball, ball + k, cmp);

	return 0;
}