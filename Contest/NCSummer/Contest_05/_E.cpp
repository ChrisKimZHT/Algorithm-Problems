#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

constexpr int MAXN = 1e4 + 10;
vector<array<int, 3>> seg;
vector<int> edge[MAXN];
vector<int> deg(MAXN);
vector<int> pos(MAXN), ans(MAXN);

void dfs(int now)
{
    int need = seg[now][2];
    for (auto &nxt : edge[now])
    {
        dfs(nxt);
        need ^= seg[nxt][2];
    }
    if (!need)
        return;
    sort(edge[now].begin(), edge[now].end(), [](int a, int b)
         { return seg[a][0] < seg[b][0]; });
    if (edge[now].empty())
        swap(pos[seg[now][0]], pos[seg[now][0] + 1]);
    else if (seg[now][0] == seg[edge[now].front()][0])
        swap(pos[seg[edge[now].front()][1]], pos[seg[edge[now].front()][1] + 1]);
    else
        swap(pos[seg[edge[now].front()][0] - 1], pos[seg[edge[now].front()][0]]);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        pos[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        if (l == r && k == 1)
        {
            cout << -1 << endl;
            return;
        }
        seg.push_back({l, r, k});
    }
    sort(seg.begin(), seg.end(), [](array<int, 3> a, array<int, 3> b)
         { return a[1] - a[0] < b[1] - b[0]; });
    for (int i = 0; i < seg.size(); i++)
    {
        for (int j = i + 1; j < seg.size(); j++)
        {
            if (seg[j][0] <= seg[i][0] && seg[i][1] <= seg[j][1])
            {
                edge[j].push_back(i);
                deg[i]++;
                break;
            }
        }
    }
    for (int i = 0; i < seg.size(); i++)
        if (!deg[i])
            dfs(i);
    for (int i = 1; i <= n; i++)
        ans[pos[i]] = i;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}