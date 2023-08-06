#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

constexpr int MAXN = 1e4 + 10;
int h[MAXN], e[MAXN], ne[MAXN], idx;

void add(int a, int b)
{
    idx++;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}

int f[MAXN];

int sg(int x)
{
    if (f[x] != -1)
        return f[x];
    set<int> st;
    for (int i = h[x]; i; i = ne[i])
    {
        int &nxt = e[i];
        st.insert(sg(nxt));
    }
    for (int i = 0;; i++)
        if (!st.count(i))
            return f[x] = i;
}

void solve()
{
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++)
    {
        int X, Y;
        cin >> X >> Y;
        add(X, Y);
    }
    memset(f, -1, sizeof(f));
    int res = 0;
    for (int i = 1; i <= K; i++)
    {
        int t;
        cin >> t;
        res ^= sg(t);
    }
    if (res)
        cout << "win" << endl;
    else
        cout << "lose" << endl;
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