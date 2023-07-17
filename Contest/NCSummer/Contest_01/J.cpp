#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;

int a[40];
const int mod = 998244353;

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
signed main()
{
    a[0] = 1;
    for (int i = 1; i <= 31; i++)
    {
        a[i] = a[i - 1] * 2;
    }

    cin >> n >> m;
    int sum = 0;
    int cnt = 0;
    int now = 1;
    m = n + m;
    while (sum + now <= n)
    {
        sum += now;
        now *= 2;
        cnt++;
    }
    // cout<<cnt<<"\n";
    int fz = 1, fm = 1;
    while (n < m)
    {
        int pos = min(sum + now - 1, m - 1);
        fz = (fz * ksm(a[cnt] - 1, pos - n + 1)) % mod;
        fm = (fm * ksm(a[cnt], pos - n + 1)) % mod;
        cnt++;
        sum += now;
        now *= 2;
        n = pos + 1;
    }
    // cout<<fz<<" "<<fm<<"\n";
    // cout<<ksm(fm,mod-2)<<"\n";
    cout << (fz * ((ksm(fm, mod - 2)) % mod)) % mod << "\n";
    /* while(1)
     {

     }*/
}