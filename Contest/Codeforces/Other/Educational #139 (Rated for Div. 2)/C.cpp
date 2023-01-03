#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int m;
    cin >> m;
    string row[2];
    cin >> row[0] >> row[1];
    bool flag = true;
    int last = (row[0][0] == 'B') ? 0 : 1;
    for (int i = 0; i < m; i++)
    {
        if (row[last][i] == 'B')
        {
            if (row[!last][i] == 'B')
                last = !last;
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
        return;
    }
    if (row[1][0] != 'B')
    {
        cout << "NO" << endl;
        return;
    }
    flag = true;
    last = 1;
    for (int i = 0; i < m; i++)
    {
        if (row[last][i] == 'B')
        {
            if (row[!last][i] == 'B')
                last = !last;
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}