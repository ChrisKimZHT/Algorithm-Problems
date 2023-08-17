#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

constexpr int MAXN = 1e6 + 10;
int num[MAXN], cnt[MAXN], idx;
int fa[MAXN][30];
int cur;
stack<int> stk;
vector<int> tree[MAXN], query[MAXN];
vector<int> ans;

void dfs(int now, int res)
{
    int &n = num[now];
    if (n != 0 && cnt[n] == 0)
        res++;
    cnt[n]++;
    for (auto &qid : query[now])
        ans[qid] = res;
    for (auto &nxt : tree[now])
        dfs(nxt, res);
    cnt[n]--;
    if (n != 0 && cnt[n] == 0)
        res--;
}

void solve()
{
    int q;
    cin >> q;
    stk.push(0);
    while (q--)
    {
        string op;
        cin >> op;
        if (op == "+")
        {
            int x;
            cin >> x;
            num[++idx] = x;
            stk.push(idx);
            tree[cur].push_back(idx);
            fa[idx][0] = cur;
            for (int i = 1; i <= 20; i++)
                fa[idx][i] = fa[fa[idx][i - 1]][i - 1];
            cur = idx;
        }
        else if (op == "-")
        {
            int k;
            cin >> k;
            for (int i = 20; i >= 0; i--)
                if (k >> i & 1)
                    cur = fa[cur][i];
            stk.push(cur);
        }
        else if (op == "!")
        {
            stk.pop();
            cur = stk.top();
        }
        else // if (op == "?")
        {
            query[cur].push_back(ans.size());
            ans.push_back(0);
        }
    }
    dfs(0, 0);
    for (auto &ele : ans)
        cout << ele << endl;
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