#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    string s;
    cin >> s;
    if (s.size() == 6)
    {
        cout << s.substr(0, 4) << '-' << s.substr(4, 2) << endl;
        return;
    }
    int year = stoi(s.substr(0, 2));
    if (year < 22)
    {
        cout << "20" << s.substr(0, 2) << '-' << s.substr(2, 2) << endl;
    }
    else
    {
        cout << "19" << s.substr(0, 2) << '-' << s.substr(2, 2) << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}