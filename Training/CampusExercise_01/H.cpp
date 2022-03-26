#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	bool light[5020]{};
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		for (int j = i; j <= N; j += i)
		{
			light[j] = !light[j];
		}
	}
	bool flag = false;
	for (int i = 1; i <= N; i++)
	{
		if (light[i])
		{
			if (flag)
			{
				cout << ",";
			}
			cout << i;
			flag = true;
		}
	}
	return 0;
}