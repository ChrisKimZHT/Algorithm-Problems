#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N, M, S;
    cin >> N >> M >> S;
    vector<string> str(N);
    for (int i = 0; i < N; i++)
        cin >> str[i];
    vector<int> pos(N);
    stack<char> stk;
    string ans;
    int op;
    while (cin >> op, op != -1)
    {
        if (op == 0)
        {
            if (stk.empty())
                continue;
            int t = stk.top();
            stk.pop();
            ans.push_back(t);
        }
        else
        {
            op--;
            if (pos[op] == M)
                continue;
            if (stk.size() == S)
            {
                int t = stk.top();
                stk.pop();
                ans.push_back(t);
            }
            stk.push(str[op][pos[op]++]);
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}