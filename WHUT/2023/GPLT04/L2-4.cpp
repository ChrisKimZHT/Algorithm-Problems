#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> path(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int t;
            cin >> t;
            path[i].push_back(t);
        }
    }
    vector<int> save(101, -1);
    int cur = 1;
    for (int i = 1; i <= M; i++)
    {
        int op, x;
        cin >> op >> x;
        if (op == 0)
        {
            cur = path[cur][x - 1];
        }
        else if (op == 1)
        {
            save[x] = cur;
            cout << cur << endl;
        }
        else
        {
            cur = save[x];
        }
    }
    cout << cur << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}