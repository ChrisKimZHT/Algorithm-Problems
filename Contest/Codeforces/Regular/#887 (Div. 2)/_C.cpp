#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

const int MAXN = 2e5 + 10;
int a[MAXN];

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (a[1] != 1)
    {
        cout << "1" << endl;
        return;
    }
    int pos = 1, nxt = 0;
    for (int i = 0; i < k; i++)
    {
        while (pos + nxt >= a[nxt + 1])
        {
            if (nxt >= n)
                break;
            nxt++;
        }
        pos += nxt;
    }
    cout << pos << endl;
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