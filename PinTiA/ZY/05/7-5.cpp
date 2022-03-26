#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int a1, b1, a2, b2;
	scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);
	if (1.0 * a1 / b1 == 1.0 * a2 / b2)
		cout << a1 << '/' << b1 << " = " << a2 << '/' << b2 << endl;
	else if (1.0 * a1 / b1 > 1.0 * a2 / b2)
		cout << a1 << '/' << b1 << " > " << a2 << '/' << b2 << endl;
	else
		cout << a1 << '/' << b1 << " < " << a2 << '/' << b2 << endl;
	return 0;
}