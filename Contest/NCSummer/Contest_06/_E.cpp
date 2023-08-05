#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 10), pre_c(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] &= 1;
        pre_c[i] = pre_c[i - 1] + a[i];
    }
    // for (int i = 1; i <= n; i++)
    //     cout << pre_c[i] << " \n"[i == n];
    int first_1 = find(a.begin() + 1, a.begin() + n, 1) - a.begin();
    vector<int> pre_0(n + 10), pre_1(n + 10);
    int len = 0, st = false;
    for (int i = 1; i <= n; i++)
    {
        pre_0[i] = pre_0[i - 1];
        if (a[i])
        {
            st = st ^ 1;
            if (st)
                len = 0;
            else
                pre_0[i] += len + 1;
        }
        len++;
    }
    // for (int i = 1; i <= n; i++)
    //     cout << pre_0[i] << " \n"[i == n];
    len = 0, st = false;
    for (int i = first_1 + 1; i <= n; i++)
    {
        pre_1[i] = pre_1[i - 1];
        if (a[i])
        {
            st = st ^ 1;
            if (st)
                len = 0;
            else
                pre_1[i] += len + 1;
        }
        len++;
    }
    // for (int i = 1; i <= n; i++)
    //     cout << pre_1[i] << " \n"[i == n];
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        int st = 0;
        if (pre_c[l] != pre_c[l - 1])
            st = pre_c[l] & 1 ^ 1;
        else
            st = pre_c[l] & 1;
        int len = r - l + 1, rng = 0, cnt = pre_c[r] - pre_c[l - 1];
        if (st)
            rng = pre_1[r] - pre_1[l - 1];
        else
            rng = pre_0[r] - pre_0[l - 1];
        if (cnt & 1)
        {
            cout << "NO" << endl;
            continue;;
        }
        cnt /= 2;
        if (cnt + (len - rng) >= k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
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