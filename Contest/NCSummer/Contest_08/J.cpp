#include <bits/stdc++.h>
#define int long long
// #define INF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define FOR(i, x, y) for (int i = x; i <= y; i++)
using namespace std;
int lowbit(int x)
{
    return -x & x;
}
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

int n;
int a[N];
int mov[10] = {7, -3, -3, 7, -3, -3, 7, -3, -3, 7};
void solve()
{
    cin >> n;
    if (n % 10 <= 4)
    {
        for (int i = 1; i <= n % 10; i++)
            a[i] = i;
    }
    else if (n % 10 == 5)
    {
        a[1] = 1, a[2] = 4, a[3] = 3, a[4] = 2, a[5] = 5;
    }
    else if (n % 10 == 6)
    {
        a[1] = 1, a[2] = 4, a[3] = 3, a[4] = 2, a[5] = 5, a[6] = 6;
    }
    else if (n % 10 == 7)
    {
        a[1] = 1, a[2] = 2, a[3] = 5, a[4] = 6, a[5] = 3, a[6] = 4, a[7] = 7;
    }
    else if (n % 10 == 8)
    {
        a[1] = 1, a[2] = 2, a[3] = 3, a[4] = 4, a[5] = 7, a[6] = 6, a[7] = 5, a[8] = 8;
    }
    else if (n % 10 == 9)
    {
        a[1] = 1, a[2] = 2, a[3] = 3, a[4] = 4, a[5] = 7, a[6] = 6, a[7] = 5, a[8] = 8, a[9] = 9;
    }
    int cnt = 0;
    for (int i = n % 10 + 1; i <= n; i++)
    {
        a[i] = a[i - 1] + mov[cnt % 10];
        cnt++;
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " \n"[i == n];
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
