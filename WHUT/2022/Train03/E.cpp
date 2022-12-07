#include <iostream>
#include <queue>
#include <set>
#include <cstring>
#define endl '\n'

using namespace std;

const int MAXN = 1e4 + 10, INF = 0x3f3f3f3f;
int dis[MAXN], st, ed;
int prime[MAXN], idx;
bool not_prime[MAXN];
void init_prime()
{
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i < MAXN; i++)
    {
        if (!not_prime[i])
            prime[idx++] = i;
        for (int j = 0; j < idx && i * prime[j] < MAXN; j++)
        {
            not_prime[i * prime[j]] = true;
            if (!(i % prime[j]))
                break;
        }
    }
}

set<int> gen(int x)
{
    set<int> res;
    int oooi = x - x % 10;
    int ooio = x - x % 100 + x % 10;
    int oioo = x - x % 1000 + x % 100;
    int iooo = x % 1000;
    for (int i = 0; i < 10; i++)
        res.insert(oooi + i);
    for (int i = 0; i < 10; i++)
        res.insert(ooio + i * 10);
    for (int i = 0; i < 10; i++)
        res.insert(oioo + i * 100);
    for (int i = 1; i < 10; i++)
        res.insert(iooo + i * 1000);
    res.erase(x);
    return res;
}

void bfs()
{
    queue<int> que;
    que.push(st);
    dis[st] = 0;
    while (que.size())
    {
        int x = que.front();
        que.pop();
        if (x == ed)
            return;
        set<int> s = gen(x);
        for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
        {
            int item = *it;
            if (!not_prime[item] && dis[item] == INF)
            {
                dis[item] = dis[x] + 1;
                que.push(item);
            }
        }
    }
}

void solve()
{
    memset(dis, 0x3f, sizeof(dis));
    cin >> st >> ed;
    bfs();
    int ans = dis[ed];
    if (ans == INF)
        cout << "Impossible" << endl;
    else
        cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init_prime();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}