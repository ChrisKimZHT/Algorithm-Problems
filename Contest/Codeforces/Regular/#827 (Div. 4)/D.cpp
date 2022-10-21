#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
int t, n;
int idx[MAXN];

int main()
{
    cin >> t;
    while (t--)
    {
        memset(idx, 0, sizeof(idx));
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int t;
            cin >> t;
            idx[t] = max(idx[t], i);
        }
        int ans = -1;
        for (int i = 1; i <= 1000; i++)
            for (int j = i; j <= 1000; j++)
                if (idx[i] && idx[j] && __gcd(i, j) == 1)
                    ans = max(ans, idx[i] + idx[j]);
        cout << ans << endl;
    }
    return 0;
}