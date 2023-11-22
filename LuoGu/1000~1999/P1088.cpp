#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;
int N, M;
int a[MAXN];
bool st[MAXN];
bool flag;
stack<int> stk;

bool dfs(int dep)
{
    if (dep == N)
    {
        if (!flag)
        {
            flag = true;
            return false;
        }
        M--;
        if (!M)
            return true;
        return false;
    }
    for (int i = (flag ? 1 : a[dep]); i <= N; i++)
    {
        if (!st[i])
        {
            st[i] = true;
            stk.push(i);
            if (dfs(dep + 1))
                return true;
            st[i] = false;
            stk.pop();
        }
    }
    return false;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    dfs(0);
    vector<int> ans;
    while (stk.size())
        ans.push_back(stk.top()), stk.pop();
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (i != ans.size() - 1)
            cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}