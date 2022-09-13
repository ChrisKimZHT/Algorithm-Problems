#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct NODE
{
    int dist, point;
    NODE(int first, int second)
    {
        point = first;
        dist = second;
    }
    bool operator<(const NODE &x) const
    {
        return dist > x.dist;
    }
};

int main(void)
{
    int P, R;
    while (cin >> P && P)
    {
        cin >> R;
        vector<NODE> edge[100];
        for (int i = 0; i < R; i++)
        {
            int a, b, dis;
            cin >> a >> b >> dis;
            edge[a].push_back(NODE(b, dis));
            edge[b].push_back(NODE(a, dis));
        }
        priority_queue<NODE> pque;
        bool vis[100]{0, 1};
        int ans = 0;
        int i = 1;
        do
        {
            for (int j = 0; j < edge[i].size(); j++)
            {
                pque.push(edge[i][j]);
            }
            while (!pque.empty())
            {
                if (!vis[pque.top().point])
                {
                    vis[pque.top().point] = true;
                    ans += pque.top().dist;
                    i = pque.top().point;
                    pque.pop();
                    break;
                }
                else
                {
                    pque.pop();
                }
            }
        } while (!pque.empty());
        cout << ans << endl;
    }
    return 0;
}