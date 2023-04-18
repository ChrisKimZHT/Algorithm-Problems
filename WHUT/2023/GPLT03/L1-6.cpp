#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    string line;
    int cnt = 0, cntline = 0, first = -1;
    while (getline(cin, line) && line != ".")
    {
        cntline++;
        if (line.find("chi1 huo3 guo1") != line.npos)
        {
            cnt++;
            if (first == -1)
                first = cntline;
        }
    }
    if (cnt)
        cout << cntline << endl
             << first << ' ' << cnt << endl;
    else
        cout << cntline << endl
             << "-_-#" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}