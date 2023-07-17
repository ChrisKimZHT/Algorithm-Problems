#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
const int N = 1e6 + 10;
const int M = 6e5 + 5;
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

vector<int> e[N];

void add(int u, int v)
{
    e[u].push_back(v);
    e[v].push_back(u);
}
typedef pair<int, int> pii;
int d[N];

int vis[N];

struct node
{
    int x, y, z; // x-dep y-cur z-fa
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    int ans = 0;
    set<pii> st;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        st.insert({min(u, v), max(u, v)});
        add(u, v);
    }
    queue<node> q;
    q.push({0, 1, 0});
    while (q.size())
    {
        node t = q.front();
        q.pop();
        if (vis[t.y])
            continue;
        vis[t.y] = 1;
        if (t.z != 0)
        {
            st.erase({min(t.y, t.z), max(t.y, t.z)});
        }
        d[t.y] = t.x;
        for (auto it : e[t.y])
        {
            q.push({t.x + 1, it, t.y});
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (d[i] > k)
            continue;
        if (d[i] == 0 && i != 1)
            continue;
        ans++;
        if (e[i].size() == 1 && i != 1 && d[i] != k)
        {
            ans += k - d[i];
            d[i] = k;
        }
        // cout<<ans<<"\n";
    }
    for (auto it : st)
    {
        // cout<<"1\n";
        if (d[it.first] == 0 && it.first != 1)
            continue;
        ans += max(0LL, k - d[it.first]) + max(0LL, k - d[it.second]);
    }
    cout << ans << "\n";
}

signed main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}