#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

constexpr int MOD = 998244353, MAXN = 2e5 + 10;
int fa[MAXN], siz[MAXN];

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        siz[i] = 1;
    }
}

int find(int x)
{
    return (fa[x] == x) ? x : (fa[x] = find(fa[x]));
}

void merge(int aa, int bb)
{
    fa[aa] = bb;
    siz[bb] += siz[aa];
}

int quick_pow(int a, int b)
{
    int ans = 1;
    a %= MOD;
    while (b)
    {
        if (b & 1)
            ans = ans * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return ans;
}

void solve()
{
    int n, S;
    cin >> n >> S;
    init(n + 10);
    vector<array<int, 3>> edge(n + 10);
    for (int i = 1; i < n; i++)
        cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
    sort(edge.begin() + 1, edge.begin() + n, [](array<int, 3> a, array<int, 3> b)
         { return a[2] < b[2]; });
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        auto &[u, v, w] = edge[i];
        int uu = find(u), vv = find(v);
        ans = ans * quick_pow(S - w + 1, siz[uu] * siz[vv] - 1) % MOD;
        merge(uu, vv);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}