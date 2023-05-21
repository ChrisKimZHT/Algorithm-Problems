#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> fish(n);
    for (int i = 0; i < n; i++)
        cin >> fish[i].first; // 体型
    for (int i = 0; i < n; i++)
        cin >> fish[i].second; // 增加
    sort(fish.begin(), fish.end());
    priority_queue<pair<int, int>> pque;
    int now = 0;
    while (true)
    {
        while (now < n && fish[now].first <= k)
        {
            pque.push({fish[now].second, fish[now].first});
            now++;
        }
        if (pque.empty())
            break;
        auto f = pque.top();
        pque.pop();
        k += f.first;
        m--;
        if (m <= 0)
            break;
    }
    cout << k << endl;
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