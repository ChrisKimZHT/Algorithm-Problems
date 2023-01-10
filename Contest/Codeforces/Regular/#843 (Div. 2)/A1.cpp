#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            if (i == j)
                continue;
            string a = s.substr(0, i + 1),
                   b = s.substr(i + 1, j - i),
                   c = s.substr(j + 1);
            if ((a <= b && c <= b) ||
                (a >= b && c >= b))
            {
                cout << a << ' ' << b << ' ' << c << endl;
                return;
            }
        }
    }
    cout << ":(" << endl;
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