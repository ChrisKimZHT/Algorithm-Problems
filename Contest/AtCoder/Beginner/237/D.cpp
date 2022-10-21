#include <bits/stdc++.h>

using namespace std;

list<int> lst;

int main(void)
{
	int N;
	string S;
	cin >> N >> S;
	lst.push_back(0);
	auto pos = lst.end();
	for (int i = 1; i <= N; i++)
	{
		if (S[i - 1] == 'R')
		{
			lst.insert(pos, i);
		}
		else
		{
			--pos;
			lst.insert(pos, i);
		}
	}
	for (auto it = lst.begin(); it != lst.end(); ++it)
	{
		cout << *it << ' ';
	}
	cout << endl;
	return 0;
}