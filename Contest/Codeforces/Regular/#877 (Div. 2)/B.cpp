#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    int pos_1 = find(p.begin(), p.end(), 1) - p.begin();
    int pos_2 = find(p.begin(), p.end(), 2) - p.begin();
    int pos_n = find(p.begin(), p.end(), n) - p.begin();
    if (pos_1 < pos_n && pos_n < pos_2 ||
        pos_2 < pos_n && pos_n < pos_1)
    {
        cout << 1 << ' ' << 1 << endl;
        return;
    }
    if (pos_1 < pos_2)
    {
        if (pos_n > pos_2)
            cout << pos_2 + 1 << ' ' << pos_n + 1 << endl;
        else
            cout << pos_1 + 1 << ' ' << pos_n + 1 << endl;
    }
    else
    {
        if (pos_n > pos_1)
            cout << pos_1 + 1 << ' ' << pos_n + 1 << endl;
        else
            cout << pos_2 + 1 << ' ' << pos_n + 1 << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}