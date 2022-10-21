#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 2e5 + 10;
int N, M, Q;
struct DATA
{
    int op, a, b, c;
} q[MAXN];
int latest[MAXN];
int ans[MAXN];
vector<int> vis[MAXN];

int Fenwick_Tree[MAXN];
void update(int pos, int val)
{
    for (int i = pos; i < MAXN; i += i & -i)
        Fenwick_Tree[i] += val;
}
int query(int pos)
{
    int ans = 0;
    for (int i = pos; i; i -= i & -i)
        ans += Fenwick_Tree[i];
    return ans;
}

signed main()
{
    cin >> N >> M >> Q;
    for (int i = 1; i <= Q; i++)
    {
        cin >> q[i].op;
        if (q[i].op == 1)
        {
            cin >> q[i].a >> q[i].b >> q[i].c;
        }
        else if (q[i].op == 2)
        {
            cin >> q[i].a >> q[i].b;
            latest[q[i].a] = i;
        }
        else
        {
            cin >> q[i].a >> q[i].b;
            vis[latest[q[i].a]].push_back(i);
        }
    }
    for (int i = 1; i <= Q; i++)
    {
        if (q[i].op == 1)
        {
            update(q[i].a, q[i].c);
            update(q[i].b + 1, -q[i].c);
        }
        else if (q[i].op == 2)
        {
            for (int v : vis[i])
                ans[v] = q[i].b - query(q[v].b);
        }
        else
        {
            ans[i] += query(q[i].b);
            cout << ans[i] << endl;
        }
    }
    return 0;
}