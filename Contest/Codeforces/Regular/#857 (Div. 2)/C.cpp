#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> mat(n + 10, vector<ll>(m + 10));
    mt19937 rng(time(0));
    while (true)
    {
        ll target = rng() * rng();
        for (int i = 1; i <= m; i++)
            mat[1][i] = rng() * rng() % INT64_MAX;
        for (int i = 1; i <= n; i++)
            mat[i][1] = rng() * rng() % INT64_MAX;
        for (int i = 2; i <= n; i++)
            for (int j = 2; j <= m; j++)
                mat[i][j] = target ^ mat[i - 1][j - 1] ^ mat[i][j - 1] ^ mat[i - 1][j];
        set<ll> s;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                s.insert(mat[i][j]);
        if (s.size() == n * m)
            break;
    }
    cout << n * m << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << mat[i][j] << ' ';
        cout << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}