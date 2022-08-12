#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int n, m;
int h[MAXN], e[MAXN], ne[MAXN], idx;
int d[MAXN], q[MAXN], hh = 0, tt = -1;

bool toposort()
{
    for (int i = 1; i <= n; i++)
        if (!d[i])
            q[++tt] = i;
    while (hh <= tt)
    {
        int now = q[hh++];
        for (int i = h[now]; i != -1; i = ne[i])
        {
            int nxt = e[i];
            d[nxt]--;
            if (!d[nxt])
                q[++tt] = nxt;
        }
    }
    return tt == n - 1;
}

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int main()
{
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        d[y]++;
    }
    if (toposort())
    {
        for (int i = 0; i <= tt; i++)
            cout << q[i] << ' ';
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}