#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
long long power(long long a, long long b)
{
    long long x = 1, y = a;
    while (b > 0)
    {
        if (b & 1ll)
        {
            x = (x * y) % mod;
        }
        y = (y * y) % mod;
        b >>= 1;
    }
    return x % mod;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (auto &nx : s)
        {
            v[i] |= (1 << (nx - 'a'));
        }
    }
    long long res = 0;
    for (int i = 1; i < (1 << n); i++)
    {
        int ch = (1 << 26) - 1;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                ch &= v[j];
            }
        }
        int pc = __builtin_popcount((unsigned int)ch);
        if (__builtin_popcount((unsigned int)i) % 2)
        {
            res += power(pc, k);
            res %= mod;
        }
        else
        {
            res += (mod - power(pc, k));
            res %= mod;
        }
    }
    cout << res << '\n';
    return 0;
}