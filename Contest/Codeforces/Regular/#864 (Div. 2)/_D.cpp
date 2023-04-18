#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}

const int MAXN = 1e5 + 10;
vector<int> a(MAXN);
vector<int> e[MAXN];
vector<int> w(MAXN), cnt(MAXN);
vector<int> fa(MAXN);
vector<set<pair<int, int>, decltype(cmp) *>> son(MAXN, set<pair<int, int>, decltype(cmp) *>(cmp)); // cnt - id
vector<bool> st(MAXN);

pair<int, int> // weight - cnt
construct_tree(int v)
{
    cnt[v] = 1;
    w[v] = a[v];
    if (e[v].empty())
        return {w[v], cnt[v]};
    for (int i = 0; i < e[v].size(); i++)
    {
        int &ele = e[v][i];
        if (!st[ele])
        {
            st[ele] = true;
            fa[ele] = v;
            pair<int, int> res = construct_tree(ele);
            son[v].insert({res.second, ele});
            cnt[v] += res.second;
            w[v] += res.first;
            st[ele] = false;
        }
    }
    return {w[v], cnt[v]};
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    st[1] = true;
    construct_tree(1);
    while (m--)
    {
        int t, x;
        cin >> t >> x;
        if (t == 1)
        {
            cout << w[x] << endl;
        }
        else
        {
            if (son[x].empty())
                continue;
            int x_fa = fa[x];
            pair<int, int> x_son_large = *son[x].begin();
            son[x].erase(x_son_large);
            fa[x_son_large.second] = x_fa;
            fa[x] = x_son_large.second;
            int tmp_weight = w[x], tmp_cnt = cnt[x];
            w[x] -= w[x_son_large.second];
            w[x_son_large.second] = tmp_weight;
            cnt[x] -= cnt[x_son_large.second];
            cnt[x_son_large.second] = tmp_cnt;
            son[x_fa].erase({tmp_cnt, x});
            son[x_fa].insert({tmp_cnt, x_son_large.second});
            son[x_son_large.second].insert({cnt[x], x});
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}