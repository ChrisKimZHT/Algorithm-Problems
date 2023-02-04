#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char> tc;
    vector<int> pre(n), suf(n);
    for (int i = 0; i < n; i++)
    {
        tc.insert(s[i]);
        pre[i] = tc.size();
    }
    tc.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        tc.insert(s[i]);
        suf[i] = tc.size();
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
        ans = max(ans, pre[i] + suf[i + 1]);
    cout << ans << endl;
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