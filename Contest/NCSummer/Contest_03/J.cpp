#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 1e6 + 10;
vector<int> edge[MAXN];
int in[MAXN];
bool vis[MAXN];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        in[v]++;
    }
    vector<int> ans;
    queue<int> que;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            que.push(i);
            vis[i] = true;
        }
    }
    while (que.size())
    {
        for (int i = 1; i <= n; i++)
        {
            if (in[i] == 0 && !vis[i])
            {
                que.push(i);
                vis[i] = true;
            }
        }
        int now = que.front();

        ans.push_back(now);
        que.pop();
        for (auto &ele : edge[now])
            in[ele]--;
    }
    for (auto &ele : ans)
        cout << ele << ' ';
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