#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int x;
	cin >> x;
	if (x == 1)
		cout << "You were studying Higher mathematics!" << endl;
	else if (x == 2)
		cout << "You were studying Linear algebra!" << endl;
	else if (x == 3)
		cout << "You were studying Principle of computer composition!" << endl;
	else if (x == 4)
		cout << "You were studying Database system concept!" << endl;
	else
		cout << "You were playing games!" << endl;
	return 0;
}