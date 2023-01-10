#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    string s;
    cin >> s;
    if (s.find('a') == s.npos)
    {
        cout << s.front() << ' ' << s.substr(1, s.size() - 2) << ' ' << s.back() << endl;
        return;
    }
    for (int i = 1; i < s.size() - 1; i++)
    {
        if (s[i] == 'a')
        {
            cout << s.substr(0, i) << " a " << s.substr(i + 1) << endl;
            return;
        }
    }
    cout << s.front() << ' ' << s.substr(1, s.size() - 2) << ' ' << s.back() << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}