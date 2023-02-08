#include <bits/stdc++.h>

using namespace std;

struct DATA
{
    int id, count;
    int a, b;
};

int n, m, k, t;
DATA mp[110][110];
vector<int> mve;
pair<int, int> dir[5] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int main(void)
{
    cin >> n >> m >> k >> t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int id;
            cin >> id;
            if (id == 17)
            {
                int a, b;
                cin >> a >> b;
                mp[i][j].id = 17;
                mp[i][j].a = a;
                mp[i][j].b = b;
            }
            else
            {
                int cnt;
                cin >> cnt;
                mp[i][j].id = id;
                mp[i][j].count = cnt;
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        int tmp;
        cin >> tmp;
        mve.push_back(tmp);
    }
    pair<int, int> pos = {0, 0};
    for (auto i : mve)
    {
        pos.first += dir[i].first;
        pos.second += dir[i].second;
        if (mp[pos.second][pos.first].id == 17)
        {
                }
    }
    return 0;
}