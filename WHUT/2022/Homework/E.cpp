#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int limit, n, x, y;
    cin >> limit >> n >> x >> y;
    vector<pair<int, int>> znum(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> znum[i].first >> znum[i].second;
        sum += znum[i].second;
    }
    sort(znum.begin(), znum.end());
    if (!x)
    {
        cout << 1 << endl;
        return;
    }
    int min_damage = 0, summon_cnt = 0;
    for (int i = znum.size() - 1; i >= 0; i--)
    {
        if (znum[i].first == 0)
            break;
        min_damage += znum[i].second;
        summon_cnt += znum[i].first * znum[i].second;
    }
    summon_cnt = min(summon_cnt, limit - sum + min_damage);
    min_damage += summon_cnt + sum - min_damage;
    int max_damage = 0;
    for (int i = 0; i < znum.size(); i++)
    {
        max_damage += znum[i].second;
        if (znum[i].first)
        {
            if (sum + znum[i].first <= limit)
                max_damage += znum[i].first * znum[i].second;
            else if (sum + znum[i].first - znum[i].second > limit)
                max_damage += ((limit - sum + 1) + (limit - sum + znum[i].second)) * znum[i].second / 2;
            else
                max_damage += znum[i].first * (znum[i].second - sum - znum[i].first + limit) + (limit - sum + 1 + znum[i].first) * (sum + znum[i].first - limit) / 2;
        }
        sum -= znum[i].second;
    }
    cout << max_damage - min_damage + 1 << endl;
}

signed main()
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