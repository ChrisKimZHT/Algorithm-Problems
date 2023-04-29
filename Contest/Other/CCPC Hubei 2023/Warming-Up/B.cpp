#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        cout << 1 << endl;
    }
    else if (n == 2)
    {
        cout << 2 << endl;
        cout << "2 2" << endl;
    }
    else if (n >= 3)
    {
        cout << 2 * (n - 2) << endl;
        for (int i = 2; i <= n - 1; i++)
        {
            cout << i << ' ';
        }
        for (int i = n - 1; i >= 2; i--)
        {
            cout << i << ' ';
        }
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
