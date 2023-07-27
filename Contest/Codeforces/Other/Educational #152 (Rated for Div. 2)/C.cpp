#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> a(n + 10, -1), b(n + 10, -1),
        c(n + 10, -1), d(n + 10, -1);
    int right = -1, left = -1;
    for (int i = n; i >= 1; i--)
    {
        if (s[i - 1] == '1' && right == -1)
            right = i;
        else if (s[i - 1] == '0')
            right = -1;
        a[i] = right;
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == '0' && left == -1)
            left = i;
        else if (s[i - 1] == '1')
            left = -1;
        b[i] = left;
    }
    right = -1, left = -1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == '1' && right == -1)
            right = i;
        else if (s[i - 1] == '0')
            right = -1;
        c[i] = right;
    }
    for (int i = n; i >= 1; i--)
    {
        if (s[i - 1] == '0' && left == -1)
            left = i;
        else if (s[i - 1] == '1')
            left = -1;
        d[i] = left;
    }
    // for (int i = 1; i <= n; i++)
    //     cout << a[i] << " \n"[i == n];
    // for (int i = 1; i <= n; i++)
    //     cout << b[i] << " \n"[i == n];
    // for (int i = 1; i <= n; i++)
    //     cout << c[i] << " \n"[i == n];
    // for (int i = 1; i <= n; i++)
    //     cout << d[i] << " \n"[i == n];
    set<pair<int, int>> st;
    bool same = false;
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        if (l == r ||
            d[l] + 1 == c[r] ||
            d[l] != -1 && d[l] >= r ||
            c[r] != -1 && c[r] <= l)
        {

            same = true;
            continue;
        }
        // cout << (b[l - 1] == -1 ? l : b[l - 1]) << ' '
        //      << (a[r + 1] == -1 ? r : a[r + 1]) << endl;
        st.insert({b[l - 1] == -1 ? l : b[l - 1],
                   a[r + 1] == -1 ? r : a[r + 1]});
    }
    cout << st.size() + same << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}