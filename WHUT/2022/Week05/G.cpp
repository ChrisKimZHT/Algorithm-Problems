#include <bits/stdc++.h>
#define int long long

using namespace std;

int T, a, b, n, m, h;

bool valid(int cnt)
{
    int len = n + m - cnt;
    int low_hori_cnt = n / b, low_hori_layer = b - a;
    int upr_hori_cnt = len / b, upr_hori_layer = h - b;
    return low_hori_cnt * low_hori_layer + upr_hori_cnt * upr_hori_layer >= cnt;
}

signed main()
{
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> n >> m >> h;
        int l = 0, r = m - 1;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            if (valid(mid))
                l = mid;
            else
                r = mid - 1;
        }
        cout << n + m - l << endl;
    }
    return 0;
}