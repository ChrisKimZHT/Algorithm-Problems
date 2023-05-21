#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> x(n), vx(n), dx(n),
        y(n), vy(n), dy(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> vx[i] >> dx[i];
    for (int i = 0; i < n; i++)
        cin >> y[i] >> vy[i] >> dy[i];
    int px, py;
    cin >> px >> py;
    map<double, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (x[i] < px && dx[i] == 1)
            continue;
        if (x[i] > px && dx[i] == 0)
            continue;
        if (x[i] != px && vx[i] == 0)
            continue;
        int delta = abs(x[i] - px), velocity = vx[i];
        double cost = 1.0 * delta / velocity;
        mp[cost]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (y[i] < py && dy[i] == 1)
            continue;
        if (y[i] > py && dy[i] == 0)
            continue;
        if (y[i] != py && vy[i] == 0)
            continue;
        int delta = abs(y[i] - py), velocity = vy[i];
        double cost = 1.0 * delta / velocity;
        mp[cost]++;
    }
    int ans = 0, tmp = 0;
    queue<pair<double, int>> que;
    for (auto &p : mp)
    {
        while (que.size() && que.front().first + 1.0 / 24 < p.first)
        {
            tmp -= que.front().second;
            que.pop();
        }
        que.push(p);
        tmp += p.second;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}