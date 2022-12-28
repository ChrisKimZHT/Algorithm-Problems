#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        while (t--)
        {
            if (m < i)
            {
                flag = false;
                break;
            }
            m -= i;
            ans++;
        }
    }
    if (m == 0)
        flag = false;
    if (flag)
        ans = -1;
    cout << ans << endl;
    return 0;
}
