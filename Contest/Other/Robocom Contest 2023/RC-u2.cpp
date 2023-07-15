#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int N, M;
vector<pair<string, string>> d;
string name, ans, tmp;

bool dfs(int now)
{
    if (now == name.size() && tmp.size() == 2)
    {
        if (ans == "")
        {
            ans = tmp;
            return true;
        }
        else
        {
            ans = "D";
            return false;
        }
    }
    for (int j = 0; j < N; j++)
    {
        if (name.substr(now, d[j].first.size()) == d[j].first)
        {
            tmp += d[j].second;
            bool st = dfs(now + d[j].first.size());
            if (!st)
                return st;
            tmp.pop_back();
        }
    }
    if (ans == "")
    {
        ans = "D";
        return false;
    }
    return true;
}

void solve()
{
    cin >> N >> M;
    d.resize(N);
    for (int i = 0; i < N; i++)
        cin >> d[i].first >> d[i].second;
    for (int i = 0; i < M; i++)
    {
        cin >> name;
        bool known = false;
        for (int i = 0; i < N; i++)
        {
            if (d[i].first == name)
            {
                cout << d[i].second << endl;
                known = true;
                break;
            }
        }
        if (known)
            continue;
        ans = tmp = "";
        dfs(0);
        cout << ans << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}