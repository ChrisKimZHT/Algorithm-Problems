#include <bits/stdc++.h>

using namespace std;

bool light[1000010];

void swit(int L, int R)
{
	for (int i = L; i <= R; i++)
	{
		light[i] = light[i] ? false : true;
	}
	return;
}

int main(void)
{
	int T;
	cin >> T;
	int _T = 1;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		while (M--)
		{
			int L, R;
			cin >> L >> R;
			swit(L, R);
		}
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			if (light[i])
				cnt++;
		}
		cout << "Case #" << _T++ << ": " << cnt << endl;
	}
	return 0;
}