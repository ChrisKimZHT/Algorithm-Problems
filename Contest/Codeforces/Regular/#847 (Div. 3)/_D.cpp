#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        mp[t]++;
    }
    vector<int> key, value;
    for (auto pr : mp)
    {
        key.push_back(pr.first);
        value.push_back(pr.second);
    }
    int ans = 0;
    for (int i = 0; i < key.size(); i++)
    {
        if (i - 1 >= 0 && key[i] == key[i - 1] + 1)
            ans += max(0, value[i] - value[i - 1]);
        else
            ans += value[i];
    }
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