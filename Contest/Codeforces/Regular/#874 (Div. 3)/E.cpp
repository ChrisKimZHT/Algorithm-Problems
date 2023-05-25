#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<set<int>> edge(n, set<int>());
    vector<int> st(n);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        t--;
        edge[i].insert(t);
        edge[t].insert(i);
    }
    int cycle = 0, bamboo = 0;
    for (int i = 0; i < n; i++)
    {
        if (st[i])
            continue;
        queue<int> que;
        vector<int> comp;
        que.push(i);
        comp.push_back(i);
        st[i] = true;
        while (que.size())
        {
            int now = que.front();
            que.pop();
            for (int nxt : edge[now])
            {
                if (st[nxt])
                    continue;
                st[nxt] = true;
                que.push(nxt);
                comp.push_back(nxt);
            }
        }
        for (int ele : comp)
        {
            if (edge[ele].size() == 1)
            {
                bamboo++;
                cycle--;
                break;
            }
        }
        cycle++;
    }
    cout << cycle + min(1, bamboo) << ' ' << cycle + bamboo << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}