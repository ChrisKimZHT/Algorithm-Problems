#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edge(N + 1);
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        vector<bool> st(N + 1);
        queue<int> que;
        que.push(i);
        st[i] = true;
        while (que.size())
        {
            int now = que.front();
            que.pop();
            for (auto nxt : edge[now])
            {
                if (!st[nxt])
                {
                    st[nxt] = true;
                    ans++;
                    que.push(nxt);
                }
            }
        }
    }
    cout << ans - M << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}