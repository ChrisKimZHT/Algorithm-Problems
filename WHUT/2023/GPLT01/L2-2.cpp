#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N;
    cin >> N;
    vector<int> fa(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> fa[i];
    vector<vector<int>> edge(N + 1);
    int root = -1;
    for (int i = 1; i <= N; i++)
    {
        if (fa[i] != -1)
            edge[fa[i]].push_back(i);
        else
            root = i;
    }
    queue<int> que;
    vector<bool> st(N + 1);
    vector<int> grade(N + 1);
    que.push(root);
    grade[root] = 1;
    st[root] = true;
    while (que.size())
    {
        int now = que.front();
        que.pop();
        for (int i = 0; i < edge[now].size(); i++)
        {
            int nxt = edge[now][i];
            if (!st[nxt])
            {
                st[nxt] = true;
                grade[nxt] = grade[now] + 1;
                que.push(nxt);
            }
        }
    }
    int max_grade = *max_element(grade.begin(), grade.end());
    cout << max_grade << endl;
    bool flag = true;
    for (int i = 1; i <= N; i++)
    {
        if (grade[i] == max_grade)
        {
            if (!flag)
                cout << ' ';
            flag = false;
            cout << i;
        }
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