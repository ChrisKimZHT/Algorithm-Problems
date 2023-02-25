#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    for (; i < s.size() / 2; i++)
        if (s[i] != s[n - 1 - i])
            break;
    for (; i < s.size() / 2; i++)
        if (s[i] == s[n - 1 - i])
            break;
    for (; i < s.size() / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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