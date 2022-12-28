#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const long long MOD = 998244353;
long long quick_pow(long long a, long long b)
{
    a %= MOD;
    long long ans = 1;
    while (b)
    {
        if (b % 2 == 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

void solve()
{
    long long n;
    cin >> n;
    cout << (quick_pow(2, n / 2 + 1) - 2 + MOD) % MOD << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}