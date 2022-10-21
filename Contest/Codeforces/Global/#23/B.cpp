#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int a[MAXN], cnt[MAXN];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[i] = cnt[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] >= (n - i) - (cnt[n] - cnt[i]))
        {
            cout << (n - i) - (cnt[n] - cnt[i]) << endl;
            break;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}