#include <bits/stdc++.h>

using namespace std;

int stair(int);

int main(void)
{
	int N, M;
	cin >> N;
	while (N--)
	{
		cin >> M;
		cout << stair(M) << endl;
	}
	return 0;
}

int stair(int x)
{
	if (x == 1)
		return 1;
	else if (x == 2)
		return 1;
	else
		return stair(x - 1) + stair(x - 2);
}