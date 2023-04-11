#include <bits/stdc++.h>
// #define endl '\n'

using namespace std;

bool check(string &s)
{
    if (s.find("qiandao") != s.npos)
        return true;
    if (s.find("easy") != s.npos)
        return true;
    return false;
}

void solve()
{
    int N, M;
    cin >> N >> M;
    getchar();
    bool flag = false;
    for (int i = 0; i < N; i++)
    {
        string s;
        getline(cin, s);
        if (flag)
            continue;
        if (check(s))
            continue;
        if (M == 0)
        {
            cout << s << endl;
            flag = true;
            continue;
        }
        M--;
    }
    if (flag)
        return;
    cout << "Wo AK le" << endl;
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    solve();
    return 0;
}