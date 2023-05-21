#include <bits/stdc++.h>
#define int long long

using namespace std;

int fastpow(int a, int b, int mod)
{
    a %= mod;
    int ans = 1;
    while (b)
    {
        if (b % 2)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

signed main()
{
    int p, q;
    cin >> p >> q;
    int C;
    cin >> C;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e;
    for (e = phi - 1; e > 0; e--)
    {
        if (e % phi && phi % e)
            break;
    }
    int d = fastpow(e, phi - 2, phi);
    int M = fastpow(C, d, n);
    cout << M << endl;
    return 0;
}