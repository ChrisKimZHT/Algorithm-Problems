#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    string c, s;
    cin >> n >> c;
    getchar();
    getline(cin, s);
    if (n > s.size())
    {
        for (int i = 0; i < n - s.size(); i++)
            cout << c;
        cout << s << endl;
    }
    else
    {
        cout << s.substr(s.size() - n) << endl;
    }
}

signed main()
{
    solve();
    return 0;
}