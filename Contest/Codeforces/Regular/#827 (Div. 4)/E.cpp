#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 2e5 + 10;
int t;
int n, q;
int a[MAXN], ps[MAXN];

signed main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            ps[i] = ps[i - 1] + a[i];
        for (int i = 1; i <= n; i++)
            a[i] = max(a[i], a[i - 1]);
        while (q--)
        {
            int tmp;
            cin >> tmp;
            int idx = upper_bound(a + 1, a + 1 + n, tmp) - a;
            cout << ps[idx - 1] << ' ';
        }
        cout << endl;
    }
    return 0;
}