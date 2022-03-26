#include <cstring>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int SIZE = 510;
vector<int> edge[SIZE];
int match[SIZE];
bool vis[SIZE];

bool find(int x)
{
    for (int i = 0; i < edge[x].size(); i++)
    {
        int j = edge[x][i];
        if (!vis[j])
        {
            vis[j] = true;
            if (match[j] == -1 || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main(void)
{
    int num;
    while (cin >> num)
    {
        for (int i = 0; i < SIZE; i++)
            edge[i].clear();
        memset(match, -1, sizeof(match));
        for (int i = 0; i < num; i++)
        {
            int t;
            scanf("%*d: (%d)", &t);
            for (int j = 0; j < t; j++)
            {
                int x;
                cin >> x;
                edge[i].push_back(x);
            }
        }
        int res = 0;
        for (int i = 0; i < num; i++)
        {
            memset(vis, false, sizeof(vis));
            if (find(i))
                res++;
        }
        cout << num - res / 2 << endl;
    }
    return 0;
}