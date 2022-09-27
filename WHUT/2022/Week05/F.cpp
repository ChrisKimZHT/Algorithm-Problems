#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
int w[MAXN], l2r[MAXN], r2l[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> w[i];
        for (int i = 1; i <= n; i++)
            l2r[i] = l2r[i - 1] + w[i];
        for (int i = 1; i <= n; i++)
            r2l[i] = r2l[i - 1] + w[n - i + 1];
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int l = l2r[i];
            int pos = lower_bound(r2l + 1, r2l + n + 1, l) - r2l;
            int r = r2l[pos];
            if (r == l && i + pos <= n)
                ans = i + pos;
        }
        cout << ans << endl;
    }
    return 0;
}