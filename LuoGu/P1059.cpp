#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int N;
	set<int> num;
	cin >> N;
	while (N--)
	{
		int tmp;
		cin >> tmp;
		num.insert(tmp);
	}
	cout << num.size() << endl;
	for (set<int>::iterator iter = num.begin(); iter != num.end(); ++iter)
	{
		cout << *iter << ' ';
	}
	return 0;
}