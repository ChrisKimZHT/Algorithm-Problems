#include <bits/stdc++.h>

using namespace std;

const int MAXN = 11;
int N, M;
vector<int> v;
bool vis[MAXN];

void dfs(int x, int last)
{
    if (x == N)
    {
        for (auto n : v)
            cout << n << ' ';
        cout << endl;
    }
    for (int i = last + 1; i <= M; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            v.push_back(i);
            dfs(x + 1, i);
            vis[i] = false;
            v.pop_back();
        }
    }
}

int main()
{
    cin >> N >> M;
    dfs(0, 0);
    return 0;
}