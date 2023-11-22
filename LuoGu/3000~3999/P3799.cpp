#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10, MAXM = 1e3 + 10;
const long long MOD = 1e9 + 7;
long long mp[MAXN];

int main()
{
    int n;
    cin >> n;
    int emin = 0, emax = 5000;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        emin = min(emin, t);
        emax = max(emax, t);
        mp[t]++;
    }
    long long ans = 0;
    for (int i = emin + 1; i <= emax; i++)
    {
        if (mp[i] < 2)
            continue;
        for (int j = emin; j <= i / 2; j++)
        {
            if (mp[i] && mp[i - j])
                if (i != j * 2)
                    ans = (ans + ((mp[i] * (mp[i] - 1) / 2) * mp[j] * mp[i - j]) % MOD) % MOD;
                else if (mp[j] >= 2)
                    ans = (ans + (mp[i] * (mp[i] - 1) / 2) * (mp[j] * (mp[j] - 1) / 2) % MOD) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}