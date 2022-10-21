#include <bits/stdc++.h>

using namespace std;

vector<int> mat[100000];

int main(void)
{
	ios::sync_with_stdio(false);
	int H, W;
	cin >> H >> W;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			int tmp;
			cin >> tmp;
			mat[i].push_back(tmp);
		}
	}
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < H; j++)
		{
			cout << mat[j][i] << ' ';
		}
		cout << endl;
	}
	return 0;
}