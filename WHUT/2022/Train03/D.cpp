#include <iostream>
#include <queue>
#include <cstring>
#define endl '\n'

using namespace std;

const int MAXN = 1e6 + 10, INF = 0x3f3f3f3f;
int N, K;
int dis[MAXN];

int trans(int x, int type)
{
    if (type == 0)
        return x - 1;
    else if (type == 1)
        return x + 1;
    else
        return 2 * x;
}

void bfs()
{
    queue<int> que;
    que.push(N);
    dis[N] = 0;
    while (que.size())
    {
        int x = que.front();
        que.pop();
        if (x == K)
            return;
        for (int i = 0; i < 3; i++)
        {
            int nx = trans(x, i);
            if (0 <= nx && nx < MAXN && dis[nx] == INF)
            {
                dis[nx] = dis[x] + 1;
                que.push(nx);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dis, 0x3f, sizeof(dis));
    cin >> N >> K;
    bfs();
    cout << dis[K] << endl;
    return 0;
}