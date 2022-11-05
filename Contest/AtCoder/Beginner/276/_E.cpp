#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
int H, W;
pair<int, int> sr;
bool st[MAXN];
int fa[MAXN];

inline void init(int n)
{
    for (int i = 0; i < n; i++)
        fa[i] = i;
}

int find(int x)
{
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

inline void merge(int x, int y)
{
    fa[find(x)] = find(y);
}

inline int mat2arr(int x, int y)
{
    return x * W + y;
}

int main()
{
    cin >> H >> W;
    init(H * W);
    for (int i = 0; i < H; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < W; j++)
        {
            if (s[j] != '.')
                st[mat2arr(i, j)] = true;
            if (s[j] == 'S')
                sr = {i, j};
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (st[mat2arr(i, j)])
                continue;
            if (j + 1 < W && !st[mat2arr(i, j + 1)])
                merge(mat2arr(i, j), mat2arr(i, j + 1));
            if (i + 1 < H && !st[mat2arr(i + 1, j)])
                merge(mat2arr(i, j), mat2arr(i + 1, j));
        }
    }
    if (sr.second + 1 < W && sr.second - 1 >= 0 &&
        !st[mat2arr(sr.first, sr.second + 1)] &&
        !st[mat2arr(sr.first, sr.second - 1)] &&
        find(mat2arr(sr.first, sr.second + 1)) == find(mat2arr(sr.first, sr.second - 1)))
    {
        cout << "Yes" << endl;
        return 0;
    }
    if (sr.first + 1 < H && sr.first - 1 >= 0 &&
        !st[mat2arr(sr.first + 1, sr.second)] &&
        !st[mat2arr(sr.first - 1, sr.second)] &&
        find(mat2arr(sr.first + 1, sr.second)) == find(mat2arr(sr.first - 1, sr.second)))
    {
        cout << "Yes" << endl;
        return 0;
    }
    if (sr.first + 1 < H && sr.second + 1 < W &&
        !st[mat2arr(sr.first, sr.second + 1)] &&
        !st[mat2arr(sr.first + 1, sr.second)] &&
        find(mat2arr(sr.first, sr.second + 1)) == find(mat2arr(sr.first + 1, sr.second)))
    {
        cout << "Yes" << endl;
        return 0;
    }
    if (sr.first - 1 >= 0 && sr.second + 1 < W &&
        !st[mat2arr(sr.first, sr.second + 1)] &&
        !st[mat2arr(sr.first - 1, sr.second)] &&
        find(mat2arr(sr.first, sr.second + 1)) == find(mat2arr(sr.first - 1, sr.second)))
    {
        cout << "Yes" << endl;
        return 0;
    }
    if (sr.first + 1 < H && sr.second - 1 >= 0 &&
        !st[mat2arr(sr.first, sr.second - 1)] &&
        !st[mat2arr(sr.first + 1, sr.second)] &&
        find(mat2arr(sr.first, sr.second - 1)) == find(mat2arr(sr.first + 1, sr.second)))
    {
        cout << "Yes" << endl;
        return 0;
    }
    if (sr.first - 1 >= 0 && sr.second - 1 >= 0 &&
        !st[mat2arr(sr.first, sr.second - 1)] &&
        !st[mat2arr(sr.first - 1, sr.second)] &&
        find(mat2arr(sr.first, sr.second - 1)) == find(mat2arr(sr.first - 1, sr.second)))
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}