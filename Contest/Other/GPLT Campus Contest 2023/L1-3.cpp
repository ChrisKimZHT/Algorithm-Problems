#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (1.0 * y1 / x1 > 1.0 * y2 / x2)
        cout << "A" << endl;
    else
        cout << "B" << endl;
    return 0;
}