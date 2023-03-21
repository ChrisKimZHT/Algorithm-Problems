#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edge(N + 1);
    while (M--)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int K;
    cin >> K;
    while (K--)
    {
        int np;
        cin >> np;
        vector<bool> st(N + 1);
        while (np--)
        {
            int t;
            cin >> t;
            st[t] = true;
        }
        for (int i = 1; i <= N; i++)
        {
            if (!st[i])
            {
                for (auto ele : edge[i])
                {
                    if (!st[ele])
                    {
                        cout << "NO" << endl;
                        goto end;
                    }
                }
            }
        }
        cout << "YES" << endl;
    end:;
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