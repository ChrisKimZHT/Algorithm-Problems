#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int ans[MAXN];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        ans[t] = i % n + 1;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}