#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
int fa[MAXN];
bool st[MAXN];

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void solve()
{
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        fa[i] = i;
    for (int i = 1; i <= M; i++)
    {
        int A, C;
        string B, D;
        cin >> A >> B >> C >> D;
        if (find(A) == find(C))
            st[find(A)] = true;
        else
            fa[find(A)] = find(C);
    }
    set<int> c, nc;
    for (int i = 1; i <= N; i++)
    {
        int root = find(i);
        if (st[root])
            c.insert(root);
        else
            nc.insert(root);
    }
    cout << c.size() << ' ' << nc.size() << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}