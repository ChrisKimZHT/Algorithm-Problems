#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 110;
int fa[MAXN];
inline void init(int n)
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}

int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

inline void merge(int i, int j)
{
    fa[find(i)] = find(j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    init(N);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    set<int> roots;
    for (int i = 1; i <= N; i++)
        roots.insert(find(i));
    cout << roots.size() << endl;
    return 0;
}