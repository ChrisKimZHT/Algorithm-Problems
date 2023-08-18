#include <bits/stdc++.h>
#define endl '\n'
// #define int long long

using namespace std;

bool check(string a, string b, string c)
{
    return stoi(a) + stoi(b) == stoi(c);
}

void solve()
{
    string a, b, c;
    string awa;
    cin >> a >> awa >> b >> awa >> c;
    if (check(a, b, c))
    {
        cout << "Yes" << endl;
        cout << a << " + " << b << " = " << c << endl;
        return;
    }
    string aa = a, bb = b, cc = c;
    for (int i = 0; i <= a.size(); i++)
    {
        for (int j = 0; j < 10; j++)
        {
            aa.insert(aa.begin() + i, '0' + j);
            if (check(aa, b, c))
            {
                cout << "Yes" << endl;
                cout << aa << " + " << b << " = " << c << endl;
                return;
            }
            aa = a;
        }
    }
    for (int i = 0; i <= b.size(); i++)
    {
        for (int j = 0; j < 10; j++)
        {
            bb.insert(bb.begin() + i, '0' + j);
            if (check(a, bb, c))
            {
                cout << "Yes" << endl;
                cout << a << " + " << bb << " = " << c << endl;
                return;
            }
            bb = b;
        }
    }
    for (int i = 0; i <= c.size(); i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cc.insert(cc.begin() + i, '0' + j);
            if (check(a, b, cc))
            {
                cout << "Yes" << endl;
                cout << a << " + " << b << " = " << cc << endl;
                return;
            }
            cc = c;
        }
    }
    cout << "No" << endl;
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