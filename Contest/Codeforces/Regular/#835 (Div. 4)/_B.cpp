#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    char maxc = 'a';
    for (char &c : s)
        maxc = max(maxc, c);
    cout << maxc - 'a' + 1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}