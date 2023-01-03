#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i].first;
    for (int i = 0; i < n; i++)
        cin >> p[i].second;
    int max_spell_val = 0, max_spell_pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].second > max_spell_val)
        {
            max_spell_val = p[i].second;
            max_spell_pos = i;
        }
    }
    int ans = 0;
    for (int i = 0; i < max_spell_pos; i++)
    {
        ans += p[i].first + p[i].second;
    }
    for (int i = n - 1; i > max_spell_pos; i--)
    {
        ans += p[i].first + p[i].second;
    }
    ans += p[max_spell_pos].first;
    cout << ans << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}