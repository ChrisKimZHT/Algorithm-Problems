#include <bits/stdc++.h>

using namespace std;

int X, Y, Z;

int main()
{
    cin >> X >> Y >> Z;
    if ((0 < Y && Y < X) || (X < Y && Y < 0))
    {
        if ((0 < Y && Y < Z) || (Z < Y && Y < 0))
            cout << -1 << endl;
        else if (X * Z < 0)
            cout << 2 * abs(Z) + abs(X) << endl;
        else if (X * Z > 0)
            cout << abs(X) << endl;
    }
    else
    {
        cout << abs(X) << endl;
    }
    return 0;
}