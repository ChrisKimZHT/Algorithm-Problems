#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int ans_1 = 0, ans_2 = 0, ans_3 = 0;
    int hh_1 = h, hh_2 = h, hh_3 = h;
    vector<int> c_1 = {2, 2, 3}, c_2 = {2, 3, 2}, c_3 = {3, 2, 2};
    for (int i = 0; i < n; i++)
    {
        while (c_1.size() && hh_1 <= a[i])
        {
            hh_1 *= c_1.back();
            c_1.pop_back();
        }
        if (hh_1 <= a[i])
            break;
        hh_1 += a[i] / 2;
        ans_1++;
    }
    for (int i = 0; i < n; i++)
    {
        while (c_2.size() && hh_2 <= a[i])
        {
            hh_2 *= c_2.back();
            c_2.pop_back();
        }
        if (hh_2 <= a[i])
            break;
        hh_2 += a[i] / 2;
        ans_2++;
    }
    for (int i = 0; i < n; i++)
    {
        while (c_3.size() && hh_3 <= a[i])
        {
            hh_3 *= c_3.back();
            c_3.pop_back();
        }
        if (hh_3 <= a[i])
            break;
        hh_3 += a[i] / 2;
        ans_3++;
    }
    cout << max({ans_1, ans_2, ans_3}) << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}