#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> pre(n + 2), suf(n + 2);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 2)
            pre[i] = pre[i - 1] + 1;
        else
            pre[i] = pre[i - 1];
    }
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == 2)
            suf[i] = suf[i + 1] + 1;
        else
            suf[i] = suf[i + 1];
    }
    for (int i = 1; i < n; i++)
    {
        if (pre[i] == suf[i + 1])
        {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
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