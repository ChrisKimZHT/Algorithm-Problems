#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 10);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    if (mp.size() < n)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mp[a[i] & x] >= 2)
        {
            cout << 1 << endl;
            return;
        }
        if (a[i] != (a[i] & x) && mp[a[i] & x] == 1)
        {
            cout << 1 << endl;
            return;
        }
    }
    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(a[i] & x);
    if (st.size() < n)
    {
        cout << 2 << endl;
        return;
    }
    cout << -1 << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}