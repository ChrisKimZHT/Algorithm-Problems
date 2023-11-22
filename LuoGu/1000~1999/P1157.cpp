#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30;
int n, r;
bool vis[MAXN];
vector<int> ans;
void dfs(int dep, int prv)
{
    if (dep == r)
    {
        for (auto i : ans)
            cout << setw(3) << i;
        cout << endl;
        return;
    }
    for (int i = prv + 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            ans.push_back(i);
            dfs(dep + 1, i);
            vis[i] = false;
            ans.pop_back();
        }
    }
}

int main()
{
    cin >> n >> r;
    dfs(0, 0);
    return 0;
}