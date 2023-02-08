#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int xA, yA, xB, yB, xP, yP;
		cin >> xA >> yA >> xB >> yB >> xP >> yP;
		if (xA != xB && yA != yB)
		{
			cout << abs(xA - xB) + abs(yA - yB);
		}
		else if (xA == xB && ((xP > xA && xP < xB) || (xP < xA && xP > xB)) || yA == yB && ((yP > yA && yP < yB) || (yP < yA && yP > yB)))
		{
			cout << abs(xA - xB) + abs(yA - yB) + 2;
		}
		else
		{
			cout << abs(xA - xB) + abs(yA - yB);
		}
		cout << endl;
	}
	return 0;
}