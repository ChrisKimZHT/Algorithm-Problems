#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    vector<vector<int>> ans(N, vector<int>());
    int id = 1, last = -1;
    while (true)
    {
        bool flag = false;
        for (int i = 0; i < N; i++)
        {
            if (a[i] <= 0)
                continue;
            flag = true;
            if (last == i)
                id++;
            ans[i].push_back(id++);
            last = i;
            if (!ans[i].empty() && ans[i].size() % 10 == 0)
                a[i]--;
        }
        if (!flag)
            break;
    }
    for (int i = 0; i < N; i++)
    {
        cout << "#" << i + 1 << endl;
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " \n"[(j + 1) % 10 == 0];
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