#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return 1.0 * a.second / a.first > 1.0 * b.second / b.first;
}

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> tv(N);
    for (int i = 0; i < N; i++)
        cin >> tv[i].first >> tv[i].second;
    sort(tv.begin(), tv.end(), cmp);
    int ans = M / tv.front().second * tv.front().first,
        score = M / tv.front().second * tv.front().second;
    int best = INT32_MAX, gap = M - score;
    for (int i = 0; i < N; i++)
    {
        int need = (gap + tv[i].second - 1) / tv[i].second;
        best = min(best, need * tv[i].first);
    }
    cout << ans + best << endl;
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