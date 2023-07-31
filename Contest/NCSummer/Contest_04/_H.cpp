#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

constexpr int MAXN = 1010;
int split[MAXN];
vector<array<int, 3>> res;

// a-lu b-rd
bool check_split(int a, int b)
{
    if (!b)
        return a <= 7;
    int ans = 0;
    while (b)
    {
        ans += a / b;
        a %= b;
        swap(a, b);
    }
    return ans <= 24;
}

void init_split(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i / 2; j++)
        {
            // i - j >= j
            if (check_split(i - j, j))
            {
                split[i] = j;
                break;
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    //     cout << split[i] << " \n"[i == n];
}

void dfs(int x, int y, int a);
void dfs_hori(int x, int y, int r, int c);
void dfs_vert(int x, int y, int r, int c);

void dfs_hori(int x, int y, int r, int c)
{
    if (r <= 1 || c <= 1)
        return;
    int cnt = c / r;
    for (int i = 0; i < cnt; i++)
        dfs(x, y + i * r, r);
    dfs_vert(x, y + cnt * r, r, c % r);
}

void dfs_vert(int x, int y, int r, int c)
{
    if (r <= 1 || c <= 1)
        return;
    int cnt = r / c;
    for (int i = 0; i < cnt; i++)
        dfs(x + i * c, y, c);
    dfs_hori(x + cnt * c, y, r % c, c);
}

void dfs(int x, int y, int a)
{
    if (a == 1)
        return;
    res.push_back({x, y, a});
    if (split[a] == 0)
        return;
    int lu = a - split[a], rd = split[a];
    dfs(x, y, lu);
    dfs(x + lu, y + lu, rd);
    dfs_hori(x + lu, y, rd, lu);
    dfs_vert(x, y + lu, lu, rd);
}

void solve()
{
    int n;
    cin >> n;
    init_split(n);
    dfs(1, 1, n);
    cout << res.size() << endl;
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i][0] << ' ' << res[i][1] << ' ' << res[i][2] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}