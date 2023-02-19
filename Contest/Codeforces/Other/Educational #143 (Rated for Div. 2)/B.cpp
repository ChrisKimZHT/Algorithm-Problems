#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int cnt_l = 0, cnt_r = 0;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        if (l == k)
            cnt_l++;
        if (r == k)
            cnt_r++;
    }
    if (cnt_l && cnt_r)
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