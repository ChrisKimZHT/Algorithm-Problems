#include <bits/stdc++.h>

using namespace std;

string S[100010];

int main(void)
{
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> S[i];
	}
	string tmp;
	cin >> tmp;
	for (int i = 0; i < N; i++)
	{
		if (S[i] == tmp)
		{
			cout << "Yes" << endl;
			cin >> tmp;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}