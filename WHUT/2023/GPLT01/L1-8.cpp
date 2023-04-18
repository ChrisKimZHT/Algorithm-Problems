#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

void solve()
{
    int N;
    cin >> N;
    vector<pair<string, int>> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i].first >> a[i].second;
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += a[i].second;
    int avg = sum / N;
    int delta = INT32_MAX, id = -1;
    for (int i = 0; i < N; i++)
    {
        if (abs(a[i].second - avg / 2) < delta)
        {
            delta = abs(a[i].second - avg / 2);
            id = i;
        }
    }
    cout << avg / 2 << ' ' << a[id].first << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}