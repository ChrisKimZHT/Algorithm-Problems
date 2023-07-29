#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

constexpr int MAXN = 1e5 + 10;
int h[MAXN], e[MAXN], ne[MAXN], idx;

void add(int x, int y)
{
    e[++idx] = y;
    ne[idx] = h[x];
    h[x] = idx;
}

vector<int> num;

int dfs(int now)
{
    int cnt = 0;
    if (!h[now])
        cnt++;
    for (int i = h[now]; i; i = ne[i])
    {
        int nxt = e[i];
        cnt += dfs(nxt);
    }
    num.push_back(cnt);
    return cnt;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        add(p, i);
    }
    dfs(1);
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++)
        cout << num[i] << ' ';
    cout << endl;
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