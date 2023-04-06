#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> edge(n);
    vector<int> dep(n, -1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    queue<int> que;
    que.push(0);
    dep[0] = 0;
    while (que.size())
    {
        int now = que.front();
        que.pop();
        for (auto nxt : edge[now])
        {
            if (dep[nxt] == -1)
            {
                dep[nxt] = dep[now] + 1;
                que.push(nxt);
            }
        }
    }
    map<int, int> mp;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(dep[i]);
        mp[dep[i]]++;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    v.insert(v.begin(), -1);
    vector<int> ps(v.size());
    for (int i = 1; i < v.size(); i++)
        ps[i] = ps[i - 1] + mp[v[i]];
    int maxd = v.back();
    for (int i = 1; i <= n; i++)
    {
        int limd = i - maxd;
        int pos = lower_bound(v.begin(), v.end(), limd) - v.begin();
        pos--;
        pos = max(pos, 0);
        cout << ps[pos] + 1 << ' ';
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}