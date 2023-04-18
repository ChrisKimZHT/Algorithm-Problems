#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N;
    cin >> N;
    vector<set<string>> group(N);
    for (int i = 0; i < N; i++)
    {
        int K;
        cin >> K;
        while (K--)
        {
            string t;
            cin >> t;
            group[i].insert(t);
        }
    }
    int M;
    cin >> M;
    vector<string> ans;
    while (M--)
    {
        string t;
        cin >> t;
        for (int i = 0; i < N; i++)
            if (group[i].count(t) && group[i].size() >= 2)
                goto end;
        ans.push_back(t);
    end:;
    }
    if (!ans.size())
        cout << "No one is handsome";
    bool flag = false;
    map<string, bool> vis;
    for (auto ele : ans)
    {
        if (vis[ele])
            continue;
        vis[ele] = true;
        if (flag)
            cout << ' ';
        flag = true;
        cout << ele;
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