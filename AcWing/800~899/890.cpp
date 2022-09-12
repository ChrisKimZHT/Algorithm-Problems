#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20;
int n, m, p[MAXN];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> p[i];
    long long ans = 0;
    for (int i = 1; i < 1 << m; i++)
    {
        long long cnt = 0, t = 1;
        for (int j = 0; j < m; j++)
        {
            if (i >> j & 1)
            {
                cnt++;
                t *= p[j];
                if (t > n)
                {
                    t = -1;
                    break;
                }
            }
        }
        if (t != -1)
        {
            if (cnt % 2)
                ans += n / t;
            else
                ans -= n / t;
        }
    }
    cout << ans << endl;
    return 0;
}