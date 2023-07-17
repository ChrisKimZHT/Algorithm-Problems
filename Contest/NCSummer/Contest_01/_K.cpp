#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

const int MAXN = 1e5 + 10;
vector<int> e[MAXN];
set<pair<int, int>> st;
vector<int> dep(MAXN, -1);

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        st.insert({min(u, v), max(u, v)});
    }
    queue<int> que;
    que.push({1});
    dep[1] = 0;
    int ans = 0;
    while (que.size())
    {
        int now = que.front();
        que.pop();
        if (dep[now] <= k)
            ans++;
        if (e[now].size() == 1 && now != 1)
        {
            ans += max(0LL, k - dep[now]);
            dep[now] = k;
        }
        for (auto &nxt : e[now])
        {
            if (dep[nxt] == -1)
            {
                dep[nxt] = dep[now] + 1;
                st.erase({min(now, nxt), max(now, nxt)});
                que.push(nxt);
            }
        }
    }
    for (auto ele : st)
    {
        if (dep[ele.first] == -1)
            continue;
        ans += max(0LL, k - dep[ele.first]) + max(0LL, k - dep[ele.second]);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}