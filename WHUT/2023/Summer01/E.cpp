#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == '(')
            a[i] = a[i - 1] + 1;
        else
            a[i] = a[i - 1] - 1;
    }
    if (abs(a[n]) != 2)
    {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    vector<int> mn(n + 1);
    mn.back() = a.back();
    for (int i = n - 1; i >= 1; i--)
        mn[i] = min(mn[i + 1], a[i]);
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == '(')
        {
            if (a[i] < 0)
                break;
            if (mn[i] == 2 && a.back() == 2)
                ans++;
        }
        else // if (s[i - 1] == ')')
        {
            if (a[i] < -2)
                break;
            if (mn[i] == -2 && a.back() == -2)
                ans++;
            if (a[i] < 0)
                break;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}