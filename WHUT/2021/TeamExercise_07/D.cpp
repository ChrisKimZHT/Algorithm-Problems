#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 210;
int N, M;
vector<int> edge[SIZE];
bool vis[SIZE];
int match[SIZE];

bool find(int x)
{
    for (int i = 0; i < edge[x].size(); i++)
    {
        int j = edge[x][i];
        if (!vis[j])
        {
            vis[j] = true;
            if (match[j] == 0 || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> N >> M)
    {
        for (int i = 0; i < SIZE; i++)
            edge[i].clear();
        memset(match, 0, sizeof(match));
        for (int i = 1; i <= N; i++)
        {
            int S;
            cin >> S;
            for (int j = 0; j < S; j++)
            {
                int t;
                cin >> t;
                edge[i].push_back(t);
            }
        }
        int ans = 0;
        for (int i = 1; i <= N; i++)
        {
            memset(vis, false, sizeof(vis));
            if (find(i))
                ans++;
        }
        cout << ans << endl;
    }
}