#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const long long MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<long long> pow2(3010);
    pow2[0] = 1;
    for (int i = 1; i < 3010; i++)
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long xi = a[i], xj = a[j];
            int posl = lower_bound(a.begin(), a.end(), 2 * xi - xj) - a.begin();
            int posr = lower_bound(a.begin(), a.end(), 2 * xj - xi) - a.begin();
            int cnt = (posl - 1) + (n - posr + 1);
            ans = (ans + pow2[cnt]) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}