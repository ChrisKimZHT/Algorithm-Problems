#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

bool is_dang(int h, int m)
{
    if (h > 12)
        return true;
    if (h == 12 && m > 0)
        return true;
    return false;
}

int cnt_dang(int h, int m)
{
    return h - 12 + (m ? 1 : 0);
}

void solve()
{
    string s;
    cin >> s;
    int hour = stoi(s.substr(0, 2));
    int minute = stoi(s.substr(3, 2));
    if (is_dang(hour, minute))
    {
        for (int i = 0; i < cnt_dang(hour, minute); i++)
            cout << "Dang";
        cout << endl;
    }
    else
    {
        cout << "Only " << s << ".  Too early to Dang." << endl;
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