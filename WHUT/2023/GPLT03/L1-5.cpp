#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int p[4], limmin, limdelta;

bool check(int i, int mx)
{
    return p[i] >= limmin && mx - p[i] <= limdelta;
}

void solve()
{
    cin >> p[0] >> p[1] >> p[2] >> p[3] >> limmin >> limdelta;
    int cnt = 0, warning = -1, pmax = max({p[0], p[1], p[2], p[3]});
    for (int i = 0; i < 4; i++)
    {
        if (!check(i, pmax))
        {
            cnt++;
            warning = i;
        }
    }
    if (cnt == 0)
        cout << "Normal" << endl;
    else if (cnt >= 2)
        cout << "Warning: please check all the tires!" << endl;
    else
        cout << "Warning: please check #" << warning + 1 << "!" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}