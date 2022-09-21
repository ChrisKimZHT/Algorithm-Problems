#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e5 + 10;
int ps[MAXN], ans[MAXN];
int T, n;

signed main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            cin >> ps[i];
            ps[i] += ps[i - 1];
        }
        int l = 0, r = n, lst = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2)
            {
                l++;
                ans[i] = ans[i - 1] + lst;
            }
            else
            {
                r--;
                ans[i] = ans[i - 1] + ps[r] - ps[l - 1] + lst;
                lst = ans[i] - ans[i - 1];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (i - 1)
                cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
