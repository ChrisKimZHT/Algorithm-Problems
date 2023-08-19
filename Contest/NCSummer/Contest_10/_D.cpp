#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

int sg(string &s)
{
    int len = s.size();
    int mid = len / 2;
    int cnt_l = 0, cnt_r = 0;
    for (int i = 0; i <= mid - 1; i++)
        if (s[i] == '1')
            cnt_l++;
    for (int i = mid; i < len; i++)
        if (s[i] == '1')
            cnt_r++;
    if (len % 2)
    {
        cnt_r -= s[mid] - '0';
        if (s[mid] == '0')
            return (cnt_l + cnt_r) % 2;
        if (cnt_l == 0 || cnt_r == 0)
            return max(cnt_l, cnt_r) % 2;
        if (cnt_l == 1 || cnt_r == 1)
            return 2 + (max(cnt_l, cnt_r) + 1) % 2;
        return (cnt_l + cnt_r + 1) % 2;
    }
    return (cnt_l + cnt_r) % 2;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    while (n--)
    {
        string s;
        cin >> s;
        ans ^= sg(s);
    }
    if (ans)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
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