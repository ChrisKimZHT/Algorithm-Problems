#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> mat(N + 10, vector<int>(N + 10, INT32_MAX));
    for (int i = 0; i < M; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        mat[a][b] = w;
        mat[b][a] = w;
    }
    int K;
    cin >> K;
    vector<pair<int, int>> ans;
    int cnt = 0;
    for (int i = 1; i <= K; i++)
    {
        bool flag = true;
        int n;
        cin >> n;
        if (n != N)
            flag = false;
        vector<bool> vis(N + 10);
        int dist = 0, last = 0;
        for (int j = 0; j < n; j++)
        {
            int v;
            cin >> v;
            if (!flag)
                continue;
            if (!vis[v])
            {
                vis[v] = true;
                int w = mat[last][v];
                if (w == INT32_MAX)
                    flag = false;
                dist += w;
                last = v;
            }
            else
            {
                flag = false;
            }
        }
        int w = mat[last][0];
        if (w == INT32_MAX)
            flag = false;
        if (!flag)
            continue;
        cnt++;
        dist += w;
        ans.push_back({i, dist});
    }
    int d_min = INT32_MAX, d_id = -1;
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].second < d_min)
        {
            d_min = ans[i].second;
            d_id = ans[i].first;
        }
    }
    cout << cnt << endl
         << d_id << ' ' << d_min << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}