#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<ll>> mat_mul_2d(vector<vector<ll>> a, vector<vector<ll>> b, ll p)
{
    vector<vector<ll>> ans(2, vector<ll>(2));
    ans[0][0] = ((a[0][0] * b[0][0]) % p + (a[0][1] * b[1][0]) % p) % p;
    ans[0][1] = ((a[0][0] * b[0][1]) % p + (a[0][1] * b[1][1]) % p) % p;
    ans[1][0] = ((a[1][0] * b[0][0]) % p + (a[1][1] * b[1][0]) % p) % p;
    ans[1][1] = ((a[1][0] * b[0][1]) % p + (a[1][1] * b[1][1]) % p) % p;
    return ans;
}

vector<vector<ll>> mat_fastpow_2d(vector<vector<ll>> a, ll n, ll p)
{
    vector<vector<ll>> ans(2, vector<ll>(2));
    ans[0][0] = ans[1][1] = 1;
    while (n)
    {
        if (n % 2)
            ans = mat_mul_2d(ans, a, p);
        a = mat_mul_2d(a, a, p);
        n >>= 1;
    }
    return ans;
}

void solve()
{
    ll A, X, M;
    cin >> A >> X >> M;
    vector<vector<ll>> mat = {{A, 1}, {0, 1}};
    vector<vector<ll>> ans = mat_fastpow_2d(mat, X, M);
    cout << ans[0][1] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}