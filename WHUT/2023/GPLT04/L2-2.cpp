#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<vector<int>> edge;
vector<int> tmp, ans;

void dfs(int v)
{
    if (tmp.size() > ans.size())
        ans = tmp;
    if (tmp.size() == ans.size() && ans > tmp)
        ans = tmp;
    for (int ele : edge[v])
    {
        tmp.push_back(ele);
        dfs(ele);
        tmp.pop_back();
    }
}

void solve()
{
    int N;
    cin >> N;
    edge.resize(N);
    vector<bool> st(N);
    for (int i = 0; i < N; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int t;
            cin >> t;
            edge[i].push_back(t);
            st[t] = true;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (!st[i])
        {
            tmp = {i};
            dfs(i);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i == ans.size() - 1];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}