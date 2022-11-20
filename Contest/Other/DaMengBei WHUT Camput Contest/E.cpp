#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
int fa[MAXN], sz[MAXN];
inline void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        sz[i] = 1;
    }
}

int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

inline int size(int x)
{
    return sz[find(x)];
}

inline void merge(int x, int y)
{
    if (find(x) == find(y))
        return;
    sz[find(y)] += sz[find(x)];
    fa[find(x)] = find(y);
}

int main()
{
    int N, M;
    cin >> N >> M;
    init(N);
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    set<int> roots;
    vector<int> cnt;
    for (int i = 1; i <= N; i++)
    {
        int rt = find(i);
        if (roots.find(rt) == roots.end())
        {
            roots.insert(rt);
            cnt.push_back(sz[rt]);
        }
    }
    sort(cnt.begin(), cnt.end());
    int now_sz = cnt.back();
    for (int i = cnt.size() - 2; i >= 0; i--)
    {
        now_sz = now_sz + cnt[i] - 2;
        if (now_sz < 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    if (roots.size() == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    if (roots.size() == 2)
    {
        cout << 1 << endl;
        return 0;
    }
    int cnt_1 = 0;
    while (cnt_1 < cnt.size() && cnt[cnt_1] == 1)
        cnt_1++;
    if (cnt_1 <= 2)
    {
        cout << 2 << endl;
        return 0;
    }
    int pos = cnt_1;
    cnt_1 -= 2;
    for (int i = 2;; i++)
    {
        for (int j = pos; j < cnt.size(); j++)
        {
            if (cnt[j] - i <= 0)
                continue;
            cnt_1--;
            if (!cnt_1)
            {
                cout << i + 1 << endl;
                return 0;
            }
        }
    }
    return 0;
}