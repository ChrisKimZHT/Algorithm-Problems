#include <bits/stdc++.h>

//#define INF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define FOR(i, x, y) for (int i = x; i <= y; i++)
using namespace std;
int lowbit(int x)
{
    return -x & x;
}
const int mod = 998244353;
// const int mod = 1e9 + 7;
const int N = 5e5 + 10;
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

int a[5005];
int e[5005][5005];
int g[5005];
int cnt[5005][5005];
int vis[5005];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        g[i]=0;
        vis[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] < a[j])e[j][g[j]++]=i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cnt[i][j] = cnt[i][j - 1];
            if (a[j] < a[i])
                cnt[i][j] += 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int pos = cnt[j][j] - cnt[j][i - 1] + 1, num = j - i + 1;
            // cout<<a[j]<<":"<<pos<<"\n";
            int l = num - pos;
            if (l == 0)
                vis[j]--;

            if (g[j] < l)
                continue;

            if (l == 0)
            {
                if (g[j] == 0)
                    continue;
                int posr = e[j][0];
                vis[posr]++;
            }
            else if (g[j] == l)
            {
                int posl = e[j][l - 1];
                vis[posl]--;
            }
            else
            {
                int posl = e[j][l - 1], posr = e[j][l];
                vis[posl]--;
                vis[posr]++;
            }
           /* for (int k = i; k <= n; k++)
            {
                cout << vis[k] << " \n"[k == n];
            }*/
        }

        for (int j = i; j <= n; j++)
        {
            vis[j] += vis[j - 1];
            if (vis[j] >= 0)
                ans++;
        }
        for (int j = 1; j <= n; j++)
            vis[j] = 0;
       // cout << ans << "\n";
    }
    cout << ans << "\n";
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
