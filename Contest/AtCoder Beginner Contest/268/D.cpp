#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<string> S;
int rem = 16;
bool vis[10];
set<string> T;
string ans = "-1";
vector<int> stk;

void dfs(bool st)
{
    if (stk.size() == 2 * N - 1)
    {
        string str;
        for (auto t : stk)
        {
            if (t >= 0)
            {
                str += S[t];
            }
            else
            {
                for (int i = 0; i > t; i--)
                    str += '_';
            }
        }
        if (3 <= str.size() && str.size() <= 16 && T.find(str) == T.end())
            ans = str;
        return;
    }
    if (st)
    {
        for (int i = 1; i <= rem; i++)
        {
            rem -= i;
            stk.push_back(-i);
            dfs(!st);
            if (ans != "-1")
                return;
            rem += i;
            stk.pop_back();
        }
    }
    else
    {
        for (int i = 0; i < S.size(); i++)
        {
            if (!vis[i])
            {
                vis[i] = true;
                stk.push_back(i);
                dfs(!st);
                if (ans != "-1")
                    return;
                vis[i] = false;
                stk.pop_back();
            }
        }
    }
    return;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string t;
        cin >> t;
        rem -= t.size();
        S.push_back(t);
    }
    for (int i = 0; i < M; i++)
    {
        string t;
        cin >> t;
        T.insert(t);
    }
    dfs(false);
    cout << ans << endl;
    return 0;
}