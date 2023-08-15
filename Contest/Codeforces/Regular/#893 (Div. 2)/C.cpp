#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MAXN = 1e5 + 10;
bool vis[MAXN];

void solve()
{
    memset(vis, 0, sizeof(vis));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int now = i;
        while (now <= n)
        {
            if (!vis[now])
            {
                cout << now << ' ';
                vis[now] = true;
            }
            now *= 2;
        }
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            cout << i << ' ';
    cout << endl;
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