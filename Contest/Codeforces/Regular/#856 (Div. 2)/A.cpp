#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - i - 1])
            return false;
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> ss;
    for (int i = 0; i < 2 * n - 2; i++)
    {
        string s;
        cin >> s;
        if (s.size() == n - 1)
            ss.push_back(s);
    }
    string str;
    if (ss[0].substr(1, n - 2) == ss[1].substr(0, n - 2))
        str = ss[0].front() + ss[1];
    else
        str = ss[1].front() + ss[0];
    cout << (is_palindrome(str) ? "Yes" : "No") << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}