#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 2e5 + 10;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    set<int> s(a.begin(), a.end());
    int val = 0;
    for (int i = 0; i <= n; i++)
    {
        if (!s.count(i))
            break;
        val++;
    }
    int first = -1, last = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == val + 1)
        {
            first = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == val + 1)
        {
            last = i;
            break;
        }
    }
    if (first == -1)
    {
        if (val == n)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
        return;
    }
    for (int i = first; i <= last; i++)
        a[i] = val;
    set<int> ns(a.begin(), a.end());
    int nval = 0;
    for (int i = 0; i <= n; i++)
    {
        if (!ns.count(i))
            break;
        nval++;
    }
    if (val + 1 == nval)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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