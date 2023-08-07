#include <bits/stdc++.h>
// #define INF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define FOR(i, x, y) for (int i = x; i <= y; i++)
using namespace std;
int lowbit(int x) { return -x & x; }
const int mod = 998244353;
// const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int M = 6e5 + 5;
int ksm(int x, int y, int mod1 = mod)
{
    int res = 1;
    x %= mod1;
    while (y > 0)
    {
        if (y & 1)
        {
            res = res * x % mod1;
        }
        y >>= 1;
        x = (x * x) % mod1;
    }
    return res;
}
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}
typedef pair<int, int> pii;

int b[N];
int a[N][50];
int vis[50];
void solve()
{
    memset(vis, 0, sizeof(vis));
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++)
        cin >> b[i];
    for (int i = 29; i >= 0; i--)
    {
        int f = 0;
        a[1][i] = 0;
        int awa = true;
        for (int j = 1; j < n; j++)
        {
            if ((b[j] >> i) & 1)
            {
                f = 1;
                if (!a[j][i])
                    a[j + 1][i] = 1;
                else
                {
                    int flag = 0;
                    for (int k = i + 1; k <= 29; k++)
                    {
                        if (a[j][k] == 0 && a[j + 1][k] == 1)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (!flag)
                    {
                        awa = false;
                        break;
                    }
                    else
                    {
                        a[j + 1][i] = 0;
                    }
                }
            }
            else
            {
                a[j + 1][i] = a[j][i];
            }
        }
        if (awa)
            continue;
        a[1][i] = 1;
        for (int j = 1; j < n; j++)
        {
            if ((b[j] >> i) & 1)
            {
                f = 1;
                if (!a[j][i])
                    a[j + 1][i] = 1;
                else
                {
                    int flag = 0;
                    for (int k = i + 1; k <= 29; k++)
                    {
                        if (a[j][k] == 0 && a[j + 1][k] == 1)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (!flag)
                    {
                        cout << "-1\n";
                        return;
                    }
                    else
                    {
                        a[j + 1][i] = 0;
                    }
                }
            }
            else
            {
                a[j + 1][i] = a[j][i];
            }
        }
        if (!f)
            vis[i] = 1;
    }

    vector<int> v;
    for (int z = 0; z < 30; z++)
    {
        if (vis[z])
            v.push_back(z);
    }
    int x = k - 1;

    if ((1 << v.size()) < k)
    {
        cout << "-1\n";
        return;
    }

    int pos = 0;
    while (x)
    {
        if (x & 1)
        {
            for (int i = 1; i <= n; i++)
                a[i][v[pos]] = 1;
        }
        x >>= 1;
        pos++;
    }
    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        for (int j = 29; j >= 0; j--)
        {
            res <<= 1;
            res += a[i][j];
        }
        cout << res << " \n"[i == n];
    }
}

signed main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
