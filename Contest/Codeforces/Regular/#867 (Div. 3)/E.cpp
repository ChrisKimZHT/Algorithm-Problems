#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n % 2)
    {
        cout << -1 << endl;
        return;
    }
    int cnt[26]{};
    for (int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] > n / 2)
        {
            cout << -1 << endl;
            return;
        }
    }
    int pair[26]{};
    int pair_cnt = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] == s[n - i - 1])
        {
            pair_cnt++;
            pair[s[i] - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (pair[i] * 2 > pair_cnt)
        {
            cout << pair[i] << endl;
            return;
        }
    }
    cout << (pair_cnt + 1) / 2 << endl;
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