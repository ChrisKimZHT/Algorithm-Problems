#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ns;
    ns += tolower(s[0]);
    for (int i = 1; i < n; i++)
        if (tolower(s[i]) != tolower(s[i - 1]))
            ns += tolower(s[i]);
    if (ns == "meow")
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
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