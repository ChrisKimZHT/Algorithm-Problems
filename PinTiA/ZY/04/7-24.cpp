#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	set<char> a;
	char tmp;
	while ((tmp = getchar()) != '\n')
	{
		a.insert(tmp);
	}
	for (set<char>::iterator iter = a.begin(); iter != a.end(); ++iter)
	{
		cout << *iter;
	}
	return 0;
}