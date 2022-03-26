#include <bits/stdc++.h>
#define MOD 1000

using namespace std;

double useless;

long long fastpow(long long a, long long b)
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

int main(void)
{
    int T;
    cin >> T;
    for (int cse = 1; cse <= T; cse++)
    {
        long long n, k;
        cin >> n >> k;
        // cout << "Case " << cse << ": " << int(pow(10, modf(double(log10(n) * k), &useless)) * 100) << ' ' << fastpow(n, k) << endl;
        printf("Case %d: %03d %03lld\n", cse, int(pow(10, modf(double(k * log10(n)), &useless)) * 100), fastpow(n, k));
    }
    return 0;
}