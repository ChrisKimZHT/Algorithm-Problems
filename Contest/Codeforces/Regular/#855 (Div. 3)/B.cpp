#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> mp;
    for (char c : s)
        mp[c]++;
    int cnt = 0, remain = 0;
    for (int i = 0; i < 26; i++)
    {
        cnt += min(mp['a' + i], mp['A' + i]);
        remain += abs(mp['a' + i] - mp['A' + i]) / 2;
    }
    int ans = cnt + min(k, remain);
    cout << ans << endl;
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