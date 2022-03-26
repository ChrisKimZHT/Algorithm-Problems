#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	set<int> num;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		num.insert(t);
	}
	cout << num.size() << endl;
	for (auto it = num.begin(); it != num.end(); ++it)
	{
		cout << *it << ' ';
	}
	cout << endl;
	return 0;
}