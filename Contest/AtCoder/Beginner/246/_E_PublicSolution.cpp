#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ppi = pair<pi, int>;

int dx[4] = {-1, -1, 1, 1};
int dy[4] = {-1, 1, -1, 1};

int main()
{
    int n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    ax--;
    ay--;
    bx--;
    by--;
    vector<string> s(n);
    for (auto &nx : s)
    {
        cin >> nx;
    }

    vector<vector<vector<int>>> d(n, vector<vector<int>>(n, vector<int>(4, 1e9)));
    vector<vector<vector<bool>>> fl(n, vector<vector<bool>>(n, vector<bool>(4, false)));

    deque<ppi> dq;
    for (int i = 0; i < 4; i++)
    {
        int cx = ax + dx[i];
        int cy = ay + dy[i];
        if (!(0 <= cx && cx < n))
        {
            continue;
        }
        if (!(0 <= cy && cy < n))
        {
            continue;
        }
        if (s[cx][cy] == '#')
        {
            continue;
        }
        d[cx][cy][i] = 1;
        dq.push_back({{cx, cy}, i});
    }

    while (!dq.empty())
    {
        ppi od = dq.front();
        dq.pop_front();
        if (od.first == make_pair(bx, by))
        {
            cout << d[bx][by][od.second] << '\n';
            return 0;
        }
        int cx = od.first.first;
        int cy = od.first.second;
        if (fl[cx][cy][od.second])
        {
            continue;
        }
        fl[cx][cy][od.second] = true;
        int cd = d[cx][cy][od.second];

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (!(0 <= nx && nx < n))
            {
                continue;
            }
            if (!(0 <= ny && ny < n))
            {
                continue;
            }
            if (s[nx][ny] == '#')
            {
                continue;
            }

            int nd = cd;
            if (i != od.second)
            {
                nd++;
            }
            if (d[nx][ny][i] > nd)
            {
                d[nx][ny][i] = nd;
                if (i == od.second)
                {
                    dq.push_front({{nx, ny}, i});
                }
                else
                {
                    dq.push_back({{nx, ny}, i});
                }
            }
        }
    }
    cout << "-1\n";
    return 0;
}
