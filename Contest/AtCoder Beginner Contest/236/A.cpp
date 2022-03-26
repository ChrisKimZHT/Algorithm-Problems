#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	string S;
	int a, b;
	cin >> S >> a >> b;
	swap(S[a - 1], S[b - 1]);
	cout << S << endl;
	return 0;
}