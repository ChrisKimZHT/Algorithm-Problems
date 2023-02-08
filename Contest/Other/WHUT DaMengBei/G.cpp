#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int k;
    cin >> k;
    if (k == 1)
    {
        if (abs(b - c) % 3)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    else if (k == 2)
    {
        if (abs(a - c) % 3)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    else if (k == 3)
    {
        if (abs(a - b) % 3)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}