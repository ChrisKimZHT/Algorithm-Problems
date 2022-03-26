#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int T, N;
int ans = 2147483647;
vector<pair<int, int>> link[1010];
vector<pair<int, int>> selected;
bool vis[1010];

void dfs(int x)
{
    if (x == N)
    {
        int tmp = 0;
        for (vector<pair<int, int>>::iterator it = selected.begin(); it != selected.end(); ++it)
        {
            tmp += it->second;
        }
        ans = min(ans, tmp);
        return;
    }
    for (vector<pair<int, int>>::iterator it = link[x].begin(); it != link[x].end(); ++it)
    {
        if (!vis[it->first])
        {
            vis[it->first] = true;
            selected.push_back(*it);
            dfs(it->first);
            vis[it->first] = false;
            selected.pop_back();
        }
    }
}

int main(void)
{
    cin >> T >> N;
    for (int i = 0; i < T; i++)
    {
        int a, b, dist;
        cin >> a >> b >> dist;
        link[a].push_back(make_pair(b, dist));
        link[b].push_back(make_pair(a, dist));
    }
    vis[1] = true;
    dfs(1);
    cout << ans << endl;
    return 0;
}