#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> e(N + 1);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<pair<int, int>> vp;
    vector<int> color(N + 1, -1);
    bool flag = true;
    for (int i = 1; i <= N; i++)
    {
        if (color[i] == -1)
        {
            queue<int> que;
            pair<int, int> p;
            que.push(i);
            color[i] = 0;
            p.first++;
            while (que.size())
            {
                if (!flag)
                    break;
                int x = que.front();
                que.pop();
                for (auto nx : e[x])
                {
                    if (color[nx] == -1)
                    {
                        color[nx] = !color[x];
                        if (color[nx])
                            p.second++;
                        else
                            p.first++;
                        que.push(nx);
                    }
                    else if (color[nx] == color[x])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            vp.push_back(p);
        }
    }
    if (!flag)
    {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0, tmp = 0;
    for (auto &p : vp)
        ans += p.first * p.second;
    for (auto &p : vp)
    {
        ans += (p.first + p.second) * tmp;
        tmp += p.first + p.second;
    }
    ans -= M;
    cout << ans << endl;
    return 0;
}