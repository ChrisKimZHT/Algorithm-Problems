// Problem: G. Replace With Product
// Contest: Codeforces - Codeforces Round 895 (Div. 3)
// URL: https://codeforces.com/contest/1872/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 10);
    int prod = 1;
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (!flag)
            prod *= a[i];
        if (prod > 2 * n)
            flag = true;
    }
    if (flag)
    {
        int l = 1, r = n;
        while (a[l] == 1)
            l++;
        while (a[r] == 1)
            r--;
        cout << l << ' ' << r << endl;
        return;
    }
    vector<int> big;
    for (int i = 1; i <= n; i++)
        if (a[i] > 1)
            big.push_back(i);
    int mx = 0, l = 1, r = 1;
    vector<int> ps(n + 10), pm(n + 10);
    pm[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        ps[i] = ps[i - 1] + a[i];
        pm[i] = pm[i - 1] * a[i];
    }
    // for (int i = 1; i <= n; i++)
    // cout << ps[i] << " \n"[i == n];
    // for (int i = 1; i <= n; i++)
    // cout << pm[i] << " \n"[i == n];
    for (int i = 0; i < big.size(); i++)
    {
        for (int j = i; j < big.size(); j++)
        {
            int ll = big[i], rr = big[j];
            int tmp = ps[ll - 1] + (ps[n] - ps[rr]) + (pm[rr] / pm[ll - 1]);
            // cout << ll << ' ' << rr << ' ' << tmp << endl;
            if (tmp > mx)
            {
                l = ll;
                r = rr;
                mx = tmp;
            }
        }
    }
    cout << l << ' ' << r << endl;
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