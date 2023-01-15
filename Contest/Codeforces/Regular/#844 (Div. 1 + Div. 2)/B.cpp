#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        mp[t]++;
    }
    int sum = 0, ans = 1;
    for (auto pr : mp)
    {
        int cur = pr.first, cnt = pr.second;
        if (sum < cur && sum + cnt - 1 >= cur)
            ans++;
        sum += cnt;
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