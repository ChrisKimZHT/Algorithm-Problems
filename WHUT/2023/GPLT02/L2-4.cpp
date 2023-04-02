#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 550;
vector<int> edge[MAXN];
int color[MAXN];

bool check(int src)
{
    for (auto ele : edge[src])
        if (color[ele] == color[src])
            return false;
    return true;
}

void solve()
{
    int V, E, K;
    cin >> V >> E >> K;
    for (int _ = 0; _ < E; _++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int N;
    cin >> N;
    for (int _ = 0; _ < N; _++)
    {
        set<int> colors;
        for (int i = 1; i <= V; i++)
        {
            cin >> color[i];
            colors.insert(color[i]);
        }
        if (colors.size() != K)
        {
            cout << "No" << endl;
            goto end;
        }
        for (int i = 1; i <= V; i++)
        {
            if (!check(i))
            {
                cout << "No" << endl;
                goto end;
            }
        }
        cout << "Yes" << endl;
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