#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    int ans = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return ans;
}

void solve()
{
    int a, b, n;
    cin >> a >> b >> n;
    a %= n;
    b %= n;
    int ans = a * a + b * b;
    int k1, m1;
    int g1 = exgcd(a, -n, k1, m1);
    for (int i = 0; i * i <= ans; i++)
    {
        for (int j = 0; j * j <= ans; j++)
        {
            if (i == j && j == 0)
            {
                continue;
            }
            if (i % g1)
                continue;
            else
            {
                int temp = i / g1 * k1;
                if ((temp * b - j) % n == 0)
                {
                    ans = min(ans, i * i + j * j);
                }
            }
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
