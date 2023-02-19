#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    reverse(t.begin(), t.end());
    s = s + t;
    int near = 0;
    for (int i = 1; i < s.size(); i++)
        if (s[i - 1] == s[i])
            near++;
    if (near >= 2)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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