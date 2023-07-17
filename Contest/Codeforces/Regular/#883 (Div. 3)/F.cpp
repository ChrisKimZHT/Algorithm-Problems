#include <bits/stdc++.h>
// #define endl '\n'

using namespace std;

int get_inc(vector<int> a, vector<int> b)
{
    for (int i = 1; i <= 9; i++)
        if (a[i] > b[i])
            return i;
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> typ(10), ntyp(10);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        typ[t]++;
    }
    vector<int> a(n);
    int inc = 0;
    do
    {
        cout << "- 0" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            ntyp[a[i]]++;
        }
        inc = get_inc(ntyp, typ);
        typ = ntyp;
        for (auto &ele : ntyp)
            ele = 0;
    } while (!inc);
    vector<int> rem;
    for (int i = 0; i < n; i++)
        if (a[i] != inc)
            rem.push_back(i + 1);
    for (int i = 1; i <= 9; i++)
        if (i != inc)
            typ[i] = 0;
    if (n - rem.size() == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == inc)
            {
                cout << "! " << i + 1 << endl;
                return;
            }
        }
    }
    cout << "- " << rem.size() << ' ';
    for (auto &ele : rem)
        cout << ele << ' ';
    cout << endl;
    while (true)
    {
        for (int i = 0; i < n - rem.size(); i++)
        {
            cin >> a[i];
            ntyp[a[i]]++;
        }
        inc = get_inc(ntyp, typ);
        if (inc)
        {
            for (int i = 0; i < n - rem.size(); i++)
            {
                if (a[i] == inc)
                {
                    cout << "! " << i + 1 << endl;
                    return;
                }
            }
        }
        typ = ntyp;
        for (auto &ele : ntyp)
            ele = 0;
        cout << "- 0" << endl;
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}