#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = INT32_MIN;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> dp(n + 1), prev(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
    }
    int tail = -1, len = 0;
    for (int i = 1; i <= n; i++)
    {
        if (len < dp[i])
        {
            len = dp[i];
            tail = i;
        }
    }
    vector<bool> st(n + 1);
    for (int i = tail; prev[i] != -1; i = prev[i])
        st[i] = true;
    priority_queue<int> pque;
    int ans = n - len;
    for (int i = 1; i < n; i++)
    {
        if (st[i] == false && st[i + 1] == true)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (st[j] == true && st[j + 1] == false)
                {
                    pque.push(j - i);
                    ans += j - i;
                    i = j - 1;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << max(n - len, min(n - 1, ans)) << ' ';
        if (pque.size())
        {
            ans -= pque.top();
            pque.pop();
        }
    }
    cout << endl;
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