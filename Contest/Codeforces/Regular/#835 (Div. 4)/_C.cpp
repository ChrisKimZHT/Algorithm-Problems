#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector<int> ss(s);
    sort(ss.begin(), ss.end(), greater<int>());
    for (int i = 0; i < n; i++)
        cout << (s[i] == ss[0] ? ss[0] - ss[1] : s[i] - ss[0]) << ' ';
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}